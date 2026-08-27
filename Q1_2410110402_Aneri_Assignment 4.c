#include<stdio.h>
int main()
{
 int N,avg,sum=0;
 printf ("Enter the number of matches\n");
 scanf ("%d",&N);
 int A[N],B[N];
 for (int i=0;i<N;i++){
     printf("Enter runs for Match %d\n",i+1);
     printf("Team A:");
     scanf("%d", &A[i]);
     printf("Team B:");
     scanf("%d",&B[i]);
     
 }
for (int i=0;i<N;i++){
 if (A[i]>B[i]){
     printf ("Match %d Winner: Team A (%d)\n",i+1,A[i]);
 }
 else printf("Match %d Winner: Team B (%d)\n",i+1,B[i]);
}
for (int i=0;i<N;i++){
    sum=sum+A[i]+B[i];
}
avg=sum/(2*N);
printf ("Average runs per match: %d",avg);
return 0;
}
