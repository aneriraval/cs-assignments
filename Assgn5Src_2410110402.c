//ANERI RAVAL 2410110402, Assignment 5
//Q1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
int numbers[1000000];
typedef struct{
	int start;
	int end;
	long long partial_sum;
	}ThreadData;
void * sum_array(void* arg){
	ThreadData* data= (ThreadData*)arg;
	data->partial_sum=0;
	for (int i=data->start; i< data->end;i++){
		data->partial_sum+=numbers[i];//perform the sum
	}
	pthread_exit(NULL);//Terminate
	}

void run_multithreaded(int num_threads){
	    pthread_t threads[num_threads]; //List of thread ids
	    ThreadData data[num_threads]; 
	    int chunk_size= 1000000/num_threads; //Chunks are the amount of numbers each thread handles
	    long long total_sum=0;
	    struct timespec start,end; //Acts as a stopwatch
	    clock_gettime(CLOCK_MONOTONIC,&start);
	    for(int i=0;i<num_threads;i++){
		    data[i].start=i*chunk_size;
		    data[i].end= (i== num_threads-1)?1000000:(i+1)*chunk_size;
		    pthread_create(&threads[i],NULL,sum_array, &data[i]);
		    }
	    for(int i=0;i<num_threads;i++){
	    	pthread_join(threads[i],NULL);//Wait for the thread to finish
		    total_sum+=data[i].partial_sum; //combine results
		    }
	
    	clock_gettime(CLOCK_MONOTONIC,&end);
	    double time_taken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec)/1e3; //calculates time in microseconds
	    printf("Threads: %2d | Sum: %lld | Time: %.2f us\n", num_threads, total_sum, time_taken);
}

int main(){
	srand(time(NULL));
	for (int i=0; i<1000000;i++){
		numbers[i]=(rand()%1000)+1;
		}
	printf("---Sequential Approach---\n");
	struct timespec start,end;
	clock_gettime (CLOCK_MONOTONIC,&start);
	long long seq_sum=0;
	for (int i = 0; i < 1000000; i++) seq_sum += numbers[i];
    clock_gettime(CLOCK_MONOTONIC, &end);
    double seq_time = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;
    printf("Threads:  1 | Sum: %lld | Time: %.2f us\n\n", seq_sum, seq_time);

    printf("--- Multithreaded Approach ---\n");
    int thread_counts[] = {2, 4, 8, 12, 16, 32};
    for (int i = 0; i < 6; i++) {
        run_multithreaded(thread_counts[i]);
    }

    return 0;
}

//Q2
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
int numbers[1000000];
typedef struct{
	int start;
	int end;
	int prime_count;
	}ThreadData;
	
int is_prime(int n){
    if (n<=1){
        return 0;
    }
    if (n<=3){
        return 1;
    }
    for (int i=3;i<n;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
void* count_primes(void *arg){
    ThreadData*data=(ThreadData*)arg;
    data->prime_count=0;
    for (int i=data->start;i<data->end;i++){
        if (is_prime[i]==1){
            data->prime_count++;
        }
    }
    pthread_exit(NULL);
}

void run_test(int num_threads) {
    pthread_t threads[num_threads];
    ThreadData data[num_threads];
    int chunk_size = LIMIT / num_threads;
    int total_primes = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < num_threads; i++) {
        data[i].start = i * chunk_size;
        data[i].end = (i == num_threads - 1) ? LIMIT : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, count_primes, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        total_primes += data[i].prime_count;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    
    double time_taken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;

    printf("%2d\t\t%d\t\t%.2f\n", num_threads, total_primes, time_taken);
}

int main() {
    srand(time(NULL));//Random array of numbers
    for (int i = 0; i < 1000000; i++) {
        numbers[i] = (rand() % 1000) + 1;
    }
    printf("Threads\t\tPrimes Found\tTime (us)\n");
    printf("--------------------------------------------\n");
    run_test(1);
    int test_cases[] = {2, 4, 8, 12, 16, 32};
    for (int i = 0; i < 6; i++) {
        run_test(test_cases[i]);
    }

    return 0;
}

//Q3
#include <stdio.h>
#include <pthread.h>
#define INITIAL 100000
#define amt 10
#define TOTAL_WITHDRAWALS 1000000

int balance = INITIAL;
pthread_mutex_t lock;

//No synchronization
void *withdraw_unsafe(void*arg){
    for (int i=0;i<TOTAL_WITHDRAWALS;i++){
        balance=balance-amt;
    }
    return null;
}
//Mutex lock
void*withdraw_safe(void*arg){
    for (int i=0;i<TOTAL_WITHDRAWALS;i++){
        pthread_mutex_lock(&lock);//lock and key mechanism
        balance=balance-amt;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void run_simulation(void*(*func)(void*),char* mode){
    balance=INITIAL; //reset
    pthread_t t1,t2; //thread IDs
    pthread_create(&t1,NULL,func,NULL);
    pthread_create(&t2,NULL,func,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Mode:%s\n",mode);
    printf("Expected Balance:%d\n",INITIAL-(2*TOTAL_WITHDRAWALS*amt));
    printf("Actual Final Balance:%d\n\n",balance);
}
int main(){
    pthread_mutex_init(&lock,NULL);// Initialize the lock
    run_simulation(withdraw_unsafe, "Without Synchronization");
    run_simulation(withdraw_safe, "With Mutex Lock");

    pthread_mutex_destroy(&lock);//Clean up memory
    return 0;
}


