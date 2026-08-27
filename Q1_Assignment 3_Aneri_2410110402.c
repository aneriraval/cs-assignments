//Aneri Raval 2410110402
#include <stdio.h>
int main()
{
int id;
printf ("Please enter your student id\n");
scanf ("%d",&id);
int sum=0;
while (id>0)
{
    sum = sum + id%10;
    id=id/10;
}
if (sum%3==0){
    printf("You are in team A");
}
else if (sum %5==0){
    printf("You are in team B");
}
else if (sum%7==0){
    printf("You are in team C");
}
else {printf ("You are in team D");
}
return 0;
}
