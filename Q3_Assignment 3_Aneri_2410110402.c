//Aneri Raval 2410110402
#include <stdio.h>
int main()
{
int i,num,prod=1;
printf("Please enter a number\n");
scanf("%d",&num);
for(i=0;i<num;i++){
    prod=prod*(num-i);
}
printf("The factorial is %d",prod);
return 0;
}