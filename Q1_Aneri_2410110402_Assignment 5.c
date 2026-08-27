//Aneri Raval 2410110402
#include<stdio.h>

int transfer (int n, char A, char C, char B){
    
    if (n>0){
        transfer (n-1,A,B,C);
        
        printf("Move disk %d from %c to %c\n",n,A,C);
        
        transfer (n-1,B,C,A);
}

return 0;

}

int main ()
{
    int n;
    printf ("Please enter the number of discs\n");
    
    scanf ("%d",&n);
    
    transfer (n, 'A','C','B');
    
    return 0;
}

