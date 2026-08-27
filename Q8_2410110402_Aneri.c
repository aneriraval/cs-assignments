
#include <stdio.h>
//Aneri Raval 2410110402
int main()
{
int year;
printf ("Please enter a year\n");
scanf("%d",&year);
if (year%400==0){
    printf("The year is a leap year");
}
else if (year%4==0 && year%100!= 0){
    printf("The year is a leap year");
}
else printf ("The year is not a leap year");

	return 0;
}