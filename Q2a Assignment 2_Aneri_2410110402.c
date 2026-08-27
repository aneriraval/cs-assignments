
#include <stdio.h>
int main()
{
int a,r;
printf ("Are your assignments done? Put in 1 for yes and 0 for no\n");
scanf ("%d",&a);
printf ("Is it raining outside? Put in 1 for yes and 0 for no\n");
scanf ("%d",&r);
if (a==0){
    printf ("You should study");
} 
else if (a==1 && r==0){
    printf ("You can hangout with your friends");
}
else if (a==1 && r==1){
    printf ("You can watch a movie");
}
return 0;
}
    