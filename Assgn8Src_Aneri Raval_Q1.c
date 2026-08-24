//Aneri Raval q1 assgn8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void safety(int m,int n, int available[m],int allocation[n][m], int max[n][m]){
    int work[m];
    bool finish[n];
    int safeseq[n];
    int need[n][m];
    int count =0;
    for (int i=0;i<n;i++){
        finish[i]=false;
        for (int j=0;j<m;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    for (int i=0; i<m;i++){
        work[i]=available[i];
    }
    for (int i=0;i<n;i++){
        finish[i]=false;
    }
    while (count<n){
        bool found=false;
        for (int i=0;i<n;i++){
            if (finish[i]==false){
                int j;
                for (j=0;j<m;j++){
                    if (need[i][j] > work[j]){
                        break;
                    }
                }
                if (j==m){
                    for (int k=0;k<m;k++){
                        work[k]=work[k]+allocation[i][k];
                    }
                    finish[i]=true;
                    found=true;
                    safeseq[count++]=i+1;;
                }
                
            }
        }
        if (found==false){
            printf("\nsystem is not in safe state\n");
            return;
        }
    }
    printf("\nOutput: The safe sequence of execution is  ");
    for (int i=0; i<n;i++){
        printf("P%d%s",safeseq[i], (i==n-1)?"":"->");
    }
    printf("\n");
    
}

int main(){
    int n,m;
    printf ("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resource types: ");
    scanf("%d",&m);
    int alloc[n][m],max[n][m],avail[m],sumalloc[m],total[m];
    for (int j=0;j<m;j++){
        sumalloc[j]=0;
    }
   
    printf ("\nEnter Allocation Matrix:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Process %d Resource %d: ",i+1,j+1);
            scanf("%d",&alloc[i][j]);
            sumalloc[j]=alloc[i][j]+sumalloc[j];
            printf("\n");
        }
    }
    printf("\nEnter Maximum Need Matrix:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Process %d Resource %d: ",i+1, j+1);
            scanf("%d",&max[i][j]);
            printf("\n");
        }
    }
    printf("\nEnter Total resources:\n");
    for (int i=0; i<m;i++){
        printf("Process %d: ",i+1);
        scanf("%d",&total[i]);
        avail[i] = total[i] - sumalloc[i];
        printf("\n");
    }
    safety(m,n,avail,alloc,max);
    return 0;
}

