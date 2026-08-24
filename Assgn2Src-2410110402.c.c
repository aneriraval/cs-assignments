//Question 1 ANERI RAVAL 2410110402
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int source, dest;
    char buff[100];
    int n;

    if (argc!=3) {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }

    source=open(argv[1], O_RDONLY);
    if (source<0) {
        printf("Error opening source file");
        return 1;
    }

    dest=open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest<0) {
        printf("Error opening destination file");
        close(source);
        return 1;
    }

    while ((n=read(source, buff, 100))>0) {
        write(dest, buff, n);
    }

    printf("File copied successfully from %s to %s.\n", argv[1], argv[2]);
    close(source);
    close(dest);
    return 0;
}

//Question 3 ANERI RAVAL 2410110402
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;
    pid_t pid;

    printf("Enter number of child processes (1 to 10): "); // No.of child processes are input
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        pid = fork();

        if (pid == 0) {   // Child process
            printf("Child Process %d: PID = %d, Parent PID = %d\n",
                   i, getpid(), getppid());
            return 0;     // Child exits immediately
        }
    }

    // Parent waits for all children
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("Parent Process: All child processes have completed. PID = %d\n",
           getpid());

    return 0;
}

//Question 4 ANERI RAVAL 2410110402
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void quicksort(int arr[], int first, int last) { //quick sort for parent process
    int i, j, pivot, temp;
    
    if (first < last) {
        pivot = first; 
        i = first; 
        j = last;

        while (i < j) {
            while (arr[i] <= arr[pivot] && i < last){
                i++;
            }
            while (arr[j] > arr[pivot]){
                j--;
            }
            //Element swaps
            if (i < j) { 
                temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp;
            }
        }
 
        temp = arr[pivot]; //Placing pivots in the right place
        arr[pivot] = arr[j]; 
        arr[j] = temp;
	//Recursive calls
        quicksort(arr, first, j - 1); 
        quicksort(arr, j + 1, last);
    }
}

void bubblesort (int arr[], int n){ //Bubble sort algoritihm for child process
	int temp;
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if (arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}



int main (int argc, char*argv[]){
	int n = argc -1;
	int *arr= malloc (n*sizeof(int));
	for (int i=0;i<n;i++){
		arr[i] = atoi(argv[i + 1]);
	}
	pid_t pid = fork();
	if (pid<0){
		printf ("Fork failed\n"); //Error message
	}
	else if (pid ==0){
		printf ("\nOutput: [Child Process]\n");
		printf ("Child PID = %d, Parent PID = %d\n", getpid(),getppid());
		bubblesort(arr,n);
		printf("Sorted array by Child (bubble sort): "); 
		for (int i=0;i<n;i++){
			printf (" %d ", arr[i]);
		}
		printf("\n");
	}
	else if (pid>0){
		wait (NULL);
		printf("\n[Parent Process]\n");
        	printf("Parent PID = %d\n", getpid());
        	quicksort(arr, 0, n - 1);
        	printf("Sorted array by Parent (quick sort): ");
        	for (int i = 0; i < n; i++){
        		printf(" %d ", arr[i]);
       		 }
        	printf("\n");
    }

    free(arr);
    return 0;
}
	
//Question 5 Aneri Raval 2410110402
//1.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void bubblesort (int arr[], int n){ //bubblesort algorithm
	int temp;
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if (arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main (){
	int target, n;
	printf ("Enter number of elements:\n");
	scanf("%d",&n);
	int *arr= malloc(n*sizeof(int));
	printf ("Enter elements: \n");
	for (int i=0; i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter element to search: ");
	scanf ("%d", &target);
	bubblesort(arr,n);
	printf("\nOutput: [Parent Process]\nSorted Array: \n"); //print output
	for (int i = 0; i < n; i++){
	 	printf("%d ", arr[i]);
	 }
	printf("\n");
	pid_t pid=fork();
	if (pid==0){
		char *args[n+3]; //declaration of array pointers
		args[0]="./search";
		for (int i=0; i<n;i++){
			args[i+1]=malloc(12);
			sprintf(args[i+1],"%d",arr[i]);
		}
		printf("\n");
		args[n+1]=malloc(12);
		sprintf(args[n + 1], "%d", target);
        	args[n + 2] = NULL;
        	execv(args[0], args); 
    	} else {
        	wait(NULL);
        	printf("Parent process finished.\n");
    	}
    return 0;
}
//2.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int n = argc - 2; // Subtract program name and target
    int target = atoi(argv[argc - 1]); // Last argument is the target
    int arr[n];
    
    for (int i = 0; i < n; i++) arr[i] = atoi(argv[i + 1]); // Convert strings back to int

    printf("[Child Process] Child PID = %d\n", getpid());

    int low = 0, high = n - 1, mid, found = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) { found = mid; break; }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (found != -1) printf("Element %d found at position %d\n", target, found);
    else printf("Element %d not found\n", target);
    
    return 0;
}
	