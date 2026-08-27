
#include <stdio.h>
//Aneri Raval 2410110402
int main()
{
int a,b,c;
printf("Enter three numbers: a,b and c\n");
scanf ("%d,%d,%d",&a,&b,&c);
    if (a>b){ 
        if (a>c)
            printf("%d is the greatest integer\n",a);
         else 
            printf("%d is the greatest integer\n",c);
    }else if (b>c){
            printf ("%d is the greatest integer\n",b);
        }else{
             printf ("%d is the greatest integer\n",c);
    }
    
    if (a<b){
        if (a<c)
            printf ("%d is the smallest integer\n",a);
        else 
            printf ("%d is the smallest integer\n",c );
    }else if (b<c){
            printf ("%d is the smallest integer",b);
    } else{
            printf("%d is the smallest integer\n",c);}
        
    return 0;
}
    