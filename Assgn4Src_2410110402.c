//Aneri Raval 2410110402 Assign4 Src
#include <stdio.h>

struct Process {
    float at, cpubt1, cpubt2, iobt, ct, tat, wt;
    float rtcpu1, rtcpu2;
    int firstCPUstart, priority, id, iscompleted, inio;
    float io_completion;
};//struct for each process

int main() {
    int n;
    printf("Enter number of processes: "); 
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d - Arrival Time: ", p[i].id); scanf("%f", &p[i].at);
        printf("Process %d - Priority: ", p[i].id); scanf("%d", &p[i].priority);
        printf("Process %d - CPU Burst Time1: ", p[i].id); scanf("%f", &p[i].cpubt1);
        printf("Process %d - I/O Burst Time: ", p[i].id); scanf("%f", &p[i].iobt);
        printf("Process %d - CPU Burst Time2: ", p[i].id); scanf("%f", &p[i].cpubt2);
        //Inititalization
        p[i].rtcpu1 = p[i].cpubt1; 
        p[i].rtcpu2 = p[i].cpubt2; 
        p[i].firstCPUstart = -1;   
        p[i].iscompleted = 0;
        p[i].inio = 0;
    }

    int current = 0; 
    int completed = 0;
    float CPU_idle_time = 0; 
    float CPU_busy_time = 0; 

    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].inio && p[i].io_completion <= current) {
                p[i].inio = 0; 
            }
        }

        int readyqueue[100], rear = 0;

        
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current && !p[i].iscompleted && !p[i].inio) {
                readyqueue[rear++] = i;
            }
        }

        //Swapping based on priority
        for (int i = 0; i < rear - 1; i++) {
            for (int j = i + 1; j < rear; j++) {
                if (p[readyqueue[j]].priority < p[readyqueue[i]].priority) {
                    int temp = readyqueue[i];
                    readyqueue[i] = readyqueue[j];
                    readyqueue[j] = temp;
                }
            }
        }

        
        if (rear > 0) {
            int selected = readyqueue[0];
            if (p[selected].firstCPUstart == -1) {
                p[selected].firstCPUstart = current;
            }
            if (p[selected].rtcpu1 > 0) {
                p[selected].rtcpu1--;
            } else {
                p[selected].rtcpu2--;
            }

            CPU_busy_time++;
            current++;

            if (p[selected].rtcpu1 == 0 && p[selected].rtcpu2 == p[selected].cpubt2 && p[selected].iobt > 0) {
                p[selected].inio = 1;
                p[selected].io_completion = current + p[selected].iobt; 
            } 
            else if (p[selected].rtcpu1 == 0 && p[selected].rtcpu2 == 0) {
                p[selected].iscompleted = 1;
                p[selected].ct = (float)current;
                completed++;
            }
        } else {
        
            CPU_idle_time++;
            current++;
        }
    }

    // Results Display
    float total_tat=0;
    float total_wt=0;
    printf("\n%-10s %-15s %-15s %-15s %-15s\n", 
    "Process", "Completion time", "Turnaround time", "Waiting time", "Response time");
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - (p[i].cpubt1 + p[i].cpubt2 + p[i].iobt);
        if (p[i].wt < 0){
            p[i].wt = 0;
        }
        int response_time = p[i].firstCPUstart - p[i].at;
        total_tat += p[i].tat; 
        total_wt += p[i].wt;

       printf("%d         %-15.0f %-15.0f %-15.0f %-15d\n", 
               p[i].id, p[i].ct, p[i].tat, p[i].wt, response_time); 
    }

    printf("\nAverage turnaround time = %.0f/%d", total_tat, n); 
    printf("\nAverage waiting time = %.0f/%d", total_wt, n); 
    printf("\nCPU idleness = %.0f/%.0f", CPU_idle_time, (float)current); 
    printf("\nCPU usage = %.0f/%.0f\n", CPU_busy_time, (float)current);
    
    return 0;
}