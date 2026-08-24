//ANERI RAVAL 2410110402 Source Code
//Q1

#include <stdio.h>

struct Process {
    int at, bt, ct, tat, wt, id; 
};

int main() {
    int n;
    float sum_wt = 0, sum_tat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n); 
    
    struct Process p[n], temp;

    // Inputs
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1; // setting process ids as 1,2,3,4...
        printf("Process %d - Arrival Time: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Process %d - Burst Time: ", p[i].id);
        scanf("%d", &p[i].bt);
    }

    // Sorting by Arrival Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculations 
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].at) {
            current_time = p[i].at; 
        }
        p[i].ct = current_time + p[i].bt; // Completion Time
        current_time = p[i].ct;
        p[i].tat = p[i].ct - p[i].at;     // Turnaround Time
        p[i].wt = p[i].tat - p[i].bt;     // Waiting Time
        //Calculating average times
        sum_wt += p[i].wt;
        sum_tat += p[i].tat;
    }

    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
     // Average waiting and turnaround time
    printf("\nAverage Waiting Time: %.2f", sum_wt / n); 
    printf("\nAverage Turnaround Time: %.2f\n", sum_tat / n);

    return 0;
}

//Q2
#include <stdio.h>

struct Process {
    int at, bt, ct, tat, wt, id, rt; 
    int in_queue; 
};

int main() {
    int n, tq, completed = 0, current_time = 0;
    float sum_wt = 0, sum_tat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n); 
    
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d - Arrival Time: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Process %d - Burst Time: ", p[i].id);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt; //  RT = BT
        p[i].in_queue = 0;
    }

    printf("Time quantum: ");
    scanf("%d", &tq); 

    int queue[100], front = 0, rear = 0;

    while (completed < n) { //
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].rt > 0 && p[i].in_queue == 0) {
                queue[rear++] = i; 
                p[i].in_queue = 1;
            }
        }
        
        if (front == rear) {
            current_time=current_time+1; 
            continue;
        }

        int i = queue[front++]; // Remove first process
        p[i].in_queue = 0;

        if (p[i].rt > tq) { //
            current_time += tq;
            p[i].rt -= tq;

            
            for (int j = 0; j < n; j++) {
                if (p[j].at <= current_time && p[j].rt > 0 && p[j].in_queue == 0 && j != i) {
                    queue[rear++] = j;
                    p[j].in_queue = 1;
                }
            }
            queue[rear++] = i; // Put current process back at end
            p[i].in_queue = 1;
        } else {
            current_time += p[i].rt;
            p[i].rt = 0;
            p[i].ct = current_time; // Set Completion Time
            completed++;
        }
    }
    //Formatted printing
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at; //
        p[i].wt = p[i].tat - p[i].bt; //
        sum_tat += p[i].tat;
        sum_wt += p[i].wt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f", sum_wt / n); //
    printf("\nAverage Turnaround Time: %.2f\n", sum_tat / n);

    return 0;
}
