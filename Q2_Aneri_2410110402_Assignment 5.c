//Aneri Raval 2410110402
#include<stdio.h>

int mysteriousNumber (int n){
    if (n==1){
        return 1;
    }
    if (n==2){
        return 2;
    }
    
    return mysteriousNumber(n-1)+ 2*mysteriousNumber(n-2);
}
int main()
{
    int n;
    
    printf ("Please enter a positive number\n");
    
    scanf ("%d",&n);
    
    for (int i=1; i<= n; i++){
        printf ("%d ",mysteriousNumber(i));
    }
    
    return 0;
}

