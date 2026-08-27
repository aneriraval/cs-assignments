//Aneri Raval 2410110402
#include <stdio.h>
int main()
{
int onum,rnum,n,num,sum,x,i,p,pal,arm,perf,pri;
printf ("Please enter a three digit number\n");
scanf ("%d",&onum);
pal=0;
arm=0;
perf=0;
pri=0;
//Checking whether the number is a palindrome
num=onum;
rnum=0;
rnum=rnum + (num%10)*100;
num= num/10;
rnum=rnum + (num%10)*10;
num=num/10;
rnum=rnum+(num%10);
if (rnum==onum){
    printf("The number is a palindrome\n");
    pal=1;
}
//Checking whether the number is an armstrong number
sum=0;
num=onum;
while (num>0){
    x=num%10;
    sum=x*x*x+sum;
    num=num/10;
}
if (sum==onum){
    printf("The number is an armstrong number\n");
    arm=1;
}
//Checking whether the number is a perfect number
sum=0;
num=onum;
for (i=1;i<num;i++){
    if (num%i==0){
        sum=sum + i;
    }
}
if (sum==onum){
    printf ("The number is a perfect number\n");
    perf=1;
}
//Checking whether the number is prime
num=onum;
p=1;
for (i=2;i<num;i++){
    if (num%i==0){
       p=0 ;
    }
}
if (p==1){
    printf("The number is a prime number\n");
    pri=1;
}
if (pal==0 && arm==0 && perf==0 && pri==0){
    printf("The number is just an ordinary number\n");
}

return 0;
}
