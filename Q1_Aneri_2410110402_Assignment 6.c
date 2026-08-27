//Aneri Raval 2410110402
#include <stdio.h>
int main()
{
    int n,*max,*min,i;
    printf("Please enter the number of elements ");
    scanf ("%d",&n);
    int arr[n];
    printf("Please enter the array elements ");
    for (i=0;i<n;i++){
        scanf ("%d",&arr[i]);
    }
    max=&arr[0];
    min=&arr[0];
    for (i=0;i<n;i++){
        if (arr[i]>*max){
            max=&arr[i];
        }
        if (arr[i]<*min){
            min=&arr[i];
        }
    }
    printf("Maximum = %d\n",*max);
    printf("Minimum = %d",*min);
    return 0;
}
