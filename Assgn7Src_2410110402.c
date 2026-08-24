//Aneri Raval Assgn7 Src
//Q1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


int buffer[5]; //assuming buffer size=5
int count =0; //count of number of plates
int in=0; //Chef index
int out =0; //Student index
int plate_serial=201;

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

void* chef(void*arg){
    int id =*(int*)arg;
    for (int i=0;i<8; i++){ //8 is chosen so both states are displayed
        int val;
        sem_getvalue(&empty,&val);
        if (val ==0){
            printf ("Chef %d waiting...Counter full | Buffer: %d/%d\n", id, count, 5);
        }
        sem_wait(&empty); //Waiting for an empty slot
        pthread_mutex_lock(&mutex);
        
        //Critical Section
        int plate=plate_serial++;
        buffer[in]=plate;
        in=(in+1)%5;
        count++;
        printf("Chef %d prepared Plate %d | Buffer: %d/%d\n", id, plate, count, 5);
        pthread_mutex_unlock(&mutex);
        sem_post(&full); // Signal that a plate is available
        usleep(rand()%100000); //Sleep
    }
    return NULL;
}

void*student(void*arg){
    int id=*(int*)arg;
    while(1){
        int val;
        sem_getvalue(&full,&val);
        if (val == 0) {
            printf("Student %d waiting... No plates available | Buffer: %d/%d\n", id, count, 5);
        }
        sem_wait(&full); // Wait for a plate
        pthread_mutex_lock(&mutex);
        
        //Critical Section
        int plate=buffer[out];
        out=(out+1)%5;
        count--;
        printf("Student %d picked Plate %d | Buffer: %d/%d\n", id, plate, count, 5);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty); // Signal that a slot is now free
        
        usleep(rand() % 500000); //Sleep (for a random amount of time)
    }
    return NULL;
}

int main(){
    pthread_t chefs[2],students[3];
    int chef_ids[2]={1,2};
    int student_ids[3]={1,2,3};
    pthread_mutex_init(&mutex,NULL);
    sem_init(&empty, 0, 5); // Initially 5 empty slots
    sem_init(&full, 0, 0);           // Initially 0 plates
    for (int i = 0; i < 2; i++) pthread_create(&chefs[i], NULL, chef, &chef_ids[i]);
    for (int i = 0; i < 3; i++) pthread_create(&students[i], NULL, student, &student_ids[i]);

    for (int i = 0; i < 2; i++) pthread_join(chefs[i], NULL);
    
    return 0;
}

//Q2
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t printers[5];
pthread_mutex_t scanners[5];
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
int p_count=5;
int s_count=5;
void update_counts(int p_delta, int s_delta){
    //semaphore counts
    pthread_mutex_lock(&count_mutex);
    p_count+=p_delta;
    s_count+=s_delta;
    pthread_mutex_unlock(&count_mutex);
}

void *employee_task(void*arg){
    int id=*(int*)arg;
    int left_p =id;
    int right_s =(id+1)%5;
    while (1){
        //Preparing
        printf("Emp%d preparing | P:%d S:%d\n", id, p_count, s_count);
        usleep(rand() % 1000000);
        //Acquiring printer
        pthread_mutex_lock(&printers[left_p]);
        update_counts(-1,0);
        printf("Emp%d got Printer%d | P:%d S:%d\n", id, left_p, p_count, s_count);
        //Acquiring scanners
        pthread_mutex_lock(&scanners[right_s]);
        update_counts(0, -1);
        printf("Emp%d got Scanner%d | P:%d S:%d\n", id, right_s, p_count, s_count);
        //Processing
        printf("Emp%d processing | P:%d S:%d\n", id, p_count, s_count);
        usleep(rand() % 1000000);
        //Releasing
        pthread_mutex_unlock(&scanners[right_s]);
        pthread_mutex_unlock(&printers[left_p]);
        update_counts(1, 1);
        printf("Emp%d released res | P:%d S:%d\n", id, p_count, s_count);
        
        usleep(rand() % 1000000); // Wait before next cycle
    }
    return NULL;
}
int main() {
    pthread_t employees[5];
    int ids[5];

    for (int i = 0; i < 5; i++) {
        //prepares locks in memory
        pthread_mutex_init(&printers[i], NULL);
        pthread_mutex_init(&scanners[i], NULL);
        ids[i] = i;
    }

    for (int i = 0; i < 5; i++) {
        pthread_create(&employees[i], NULL, employee_task, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(employees[i], NULL);
    }

    return 0;
}    
    



    