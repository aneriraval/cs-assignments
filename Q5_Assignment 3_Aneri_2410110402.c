//Aneri Raval 2410110402
#include <stdio.h>
int main()
{
int n,i,p,sum,j;
printf("Enter a number\n");
scanf("%d",&n);
sum=0;
for (i=2;i<=n;i++){
    p=1;
    for (j=2;j<=(i-1);j++){
        if (i%j==0){
            p=0;
            break;
        }
    }
        if (p==1){
            sum=sum+i;
        }
    
}
printf("The sum of prime numbers from 1 to %d is %d\n",n,sum);
return 0;
}