//Aneri Raval 2410110402
#include <stdio.h>
int main()
{
int n,i;
int fib[10000];
printf("Enter a number\n");
scanf("%d",&n);
fib[0]=0;
fib[1]=1;
printf("%d %d ",fib[0],fib[1]);
for (i=2;i<=n;i++){
    fib[i]=fib[i-1]+fib[i-2];
    printf("%d ",fib[i]);
}
return 0;
}