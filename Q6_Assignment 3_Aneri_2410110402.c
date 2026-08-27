//Aneri Raval 2410110402
#include <stdio.h>
int main()
{
int n,i,p,j;
printf("Enter a number\n");
scanf("%d",&n);

for(i=2;i<=n;i++){
    if (n%i==0){
           p=1;
    
    for (j=2;j<=i-1;j++){
        if(i%j==0){
            p=0;
            break;
        }
    }
   
    if (p==1){
        printf("%d is a prime factor of %d\n",j,n);
    }
}
}
return 0;
}