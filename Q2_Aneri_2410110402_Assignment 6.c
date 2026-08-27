//Aneri Raval 2410110402
#include <stdio.h>
int add(int a,int b)
{
    return a+b;
}
int subtract(int a,int b)
{
    return a-b;
}
int multiply(int a, int b)
{
    return a*b;
}
float divide(int a, int b)
{
    if (b!=0){
        return (float)a/b;
    }
    else printf("Division not possible.");
}
int main()
{
    int n1,n2;
    int (*p)(int,int);
    float (*f)(int,int);
    float ans;
    char op;
    printf("Enter the first number: ");
    scanf ("%d",&n1);
    printf("Enter the second number: ");
    scanf("%d",&n2);
    printf("Enter an operation (+,-,* or /): ");
    scanf(" %c",&op);
    switch (op){
        case '+':p=add; ans=p(n1, n2);
        break;
        case '-':p=subtract; ans= p(n1, n2);
        break;
        case '*':p=multiply; ans= p(n1, n2);
        break;
        case '/':f=divide; ans= f(n1, n2);
        break;
    }
    printf("Result: %f",ans);
    return 0;
}
    