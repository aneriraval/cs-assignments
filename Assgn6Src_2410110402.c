#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define ALGORITHM_TYPE 3

// Global Parameters from inp-params.txt
int n, k;
double l1, l2;
int algorithm_type = 1;

// Synchronization Variables
atomic_int lock_var = 0;
bool *waiting; 

// Metrics for the report
double total_waiting_time = 0;
double worst_case_waiting_time = 0;
pthread_mutex_t metrics_lock = PTHREAD_MUTEX_INITIALIZER;

// File pointer for logging output
FILE *output_file;

// Helper: Get system time string 
void get_formatted_time(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 20, "%H:%M:%S", t);
}

// Exponential delay simulation 
void delay(double mean_ms) {
    double r = ((double)rand() / (RAND_MAX));
    double delay_val = -mean_ms * log(1.0 - r);
    usleep((useconds_t)(delay_val * 1000)); 
}

// Algorithm 1: TAS 
void tas_entry() {
    while (atomic_exchange_explicit(&lock_var, 1, memory_order_acquire));
}
void tas_exit() {
    atomic_store_explicit(&lock_var, 0, memory_order_release);
}

// Algorithm 2: CAS 
void cas_entry() {
    int expected = 0;
    while (!atomic_compare_exchange_strong(&lock_var, &expected, 1)) {
        expected = 0; 
    }
}
void cas_exit() {
    atomic_store(&lock_var, 0);
}

// Algorithm 3: Bounded CAS 
void bounded_cas_entry(int id) {
    waiting[id] = true;
    int expected = 0;
    bool key = true;
    while (waiting[id] && key) {
        expected = 0;
        if (atomic_compare_exchange_strong(&lock_var, &expected, 1)) {
            key = false;
        }
    }
    waiting[id] = false;
}
void bounded_cas_exit(int id) {
    int j = (id + 1) % n;
    while ((j != id) && !waiting[j]) j = (j + 1) % n;
    if (j == id) atomic_store(&lock_var, 0);
    else waiting[j] = false;
}

// The Test Function 
void* testCS(void* arg) {
    int id = *(int*)arg;
    free(arg);
    char time_buf[20];

    for (int i = 0; i < k; i++) {
        struct timespec req, enter;
        
        // --- REQUEST SECTION ---
        get_formatted_time(time_buf);
        fprintf(output_file, "%dth CS Requested at %s by thread %d\n", i+1, time_buf, id);
        clock_gettime(CLOCK_MONOTONIC, &req);

        // --- ENTRY SECTION ---
        #if ALGORITHM_TYPE == 1
            tas_entry();
        #elif ALGORITHM_TYPE == 2
            cas_entry();
        #else
            bounded_cas_entry(id);
        #endif

        // --- CRITICAL SECTION ---
        clock_gettime(CLOCK_MONOTONIC, &enter);
        get_formatted_time(time_buf);
        fprintf(output_file, "%dth CS Entered at %s by thread %d\n", i+1, time_buf, id);
        
        // Calculate metrics
        double wait_ms = (enter.tv_sec - req.tv_sec) * 1000.0 + (enter.tv_nsec - req.tv_nsec) / 1000000.0;
        pthread_mutex_lock(&metrics_lock);
        total_waiting_time += wait_ms;
        if (wait_ms > worst_case_waiting_time) worst_case_waiting_time = wait_ms;
        pthread_mutex_unlock(&metrics_lock);

        delay(l1);

        // --- EXIT SECTION ---
        #if ALGORITHM_TYPE == 1
            tas_exit();
        #elif ALGORITHM_TYPE == 2
            cas_exit();
        #else
            bounded_cas_exit(id);
        #endif

        get_formatted_time(time_buf);
        fprintf(output_file, "%dth CS Exited at %s by thread %d\n", i+1, time_buf, id);

        delay(l2);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    // 1. Read parameters from the input file
    FILE *param_file = fopen("inp-params.txt", "r"); 
    if (!param_file || fscanf(param_file, "%d %d %lf %lf", &n, &k, &l1, &l2) != 4) {
        printf("Error: Could not read inp-params.txt\n");
        return 1;
    }
    fclose(param_file);

    // Prepare for algorithm iteration
    char *filenames[] = {"TAS-Log.txt", "CAS-Log.txt", "BoundedCAS-Log.txt"};
    waiting = (bool*)calloc(n, sizeof(bool));

    // 2. Loop through each algorithm (1: TAS, 2: CAS, 3: Bounded CAS)
    for (int alg = 1; alg <= 3; alg++) {
        algorithm_type = alg; // Sets the global type for testCS
        output_file = fopen(filenames[alg - 1], "w");
        
        // Reset metrics and synchronization variables for the new run
        total_waiting_time = 0;
        worst_case_waiting_time = 0;
        atomic_store(&lock_var, 0);
        for (int i = 0; i < n; i++) waiting[i] = false;

        printf("Starting simulation for %s...\n", filenames[alg - 1]);

        pthread_t threads[n];
        for (int i = 0; i < n; i++) {
            int *id = malloc(sizeof(int));
            *id = i;
            pthread_create(&threads[i], NULL, testCS, id); 
        }

        // Wait for all threads to finish this algorithm before starting the next
        for (int i = 0; i < n; i++) {
            pthread_join(threads[i], NULL);
        }

        // Print metrics for this specific algorithm
        printf("Metrics for %s (n=%d, k=%d):\n", filenames[alg - 1], n, k);
        printf("  Average Wait Time: %.2f ms\n", total_waiting_time / (n * k)); 
        printf("  Worst Case Wait Time: %.2f ms\n\n", worst_case_waiting_time); 

        fclose(output_file);
    }

    free(waiting);
    return 0;
}