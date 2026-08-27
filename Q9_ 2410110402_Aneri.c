
#include <stdio.h>
//Aneri Raval 241010110402
int main()
{
	float l,b,a,p;

	printf("Please enter the length and breadth of the rectangle\n");
	scanf("%f,%f",&l,&b);
	a=l*b;
    p=2*l+2*b;
    if (a>p){
        printf("The area is greater than the perimeter\n");
    }
    else if (a==p){
        printf("The perimeter is equal to the area\n");
    }
    else {
        printf ("The perimeter is greater than the area\n");
    }
    return 0;
}