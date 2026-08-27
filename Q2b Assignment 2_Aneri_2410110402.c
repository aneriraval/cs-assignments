
#include <stdio.h>
int main()
{
int a,r;
printf ("Are your assignments done? Put in 1 for yes and 0 for no\n");
scanf ("%d",&a);
printf ("Is it raining outside? Put in 1 for yes and 0 for no\n");
scanf ("%d",&r);

switch (a){
    case 0:
    printf("You should study");
    break;
    case 1:
    switch(r){
        case 0:
        printf("You can hangout with your friends");
        break;
        case 1:
        printf ("You can watch a movie");
        break;
    }
}
return 0;
}