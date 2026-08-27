
#include <stdio.h>
int main()
{
printf("What day is it? Put in 1 for Monday and 2 for Tuesday\n");
int d, s1, s2;
float t1,t2;
scanf("%d",&d);
t1=(0.7/5)*60;
t2=(0.9/5)*60;

if (d==1){
    s1=1;
    s2=0;}
    else if (d==2){
        s1=0;
        s2=0;
    }
if (t2<10 && s2==1) {
    printf("Robin goes to DH2");
}
else if (t1<10 && s1==1){
    printf("Robin goes to DH1");
}
else if (t1<8) {
    printf ("Robin goes to DH1");
}
else {
    printf ("Robin goes to the nearby cafe");
}
return 0;
}
