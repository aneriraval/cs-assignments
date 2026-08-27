//Aneri Raval 2410110402
#include <stdio.h>
int main()
{
int i,num1,num2,hcf=0,cf=0;

printf("Please enter two numbers\n");
scanf("%d,%d",&num1,&num2);
for(i=1;i<=num1;i++){
    if (num1%i==0 && num2%i==0){
        cf=i;
    }
    if (cf>hcf){
        hcf=cf;
    }
}
printf("The highest common factor is %d",hcf);
return 0;
}