//Decimal to binary
#include <stdio.h>
int binary(int n,int a[], int index){
        if (n==0){
        return 0 ;
    }
        binary(n/2,a,index-1);
        a[index]=n%2;
}
int main(){
    int n,a[32]={0};
    printf("Please enter a decimal number\n");
    scanf ("%d",&n);
    if (n==0){
        printf("Binary representation is 0\n");
    }
    int temp=n, count=0;
    while (temp>0){
        temp=temp/2;
        count = count +1;
    }
    binary (n,a, count-1);
    printf("Binary equivalent:\n");
    
    for (int i=0;i<count;i++){
    printf ("%d",a[i]);
}
return 0;
}