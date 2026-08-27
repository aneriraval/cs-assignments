
#include <stdio.h>
int main()
{
float h,w,bmi;
printf("Please enter your height (in meters)\n");
scanf("%f",&h);
printf ("Please enter your weight (in kg)\n");
scanf("%f",&w);
bmi=w/(h*h);
printf ("Your bmi is %f\n",bmi);
if (17<=bmi && bmi<18.5) {
    printf ("Mild thinness");
}
        else if (18.5<=bmi && bmi<25) {
            printf("Normal weight");
        }
                else if (bmi>25){
                    printf("Overweight");
                }
                        else if (bmi <17){
                            printf ("Inhumane");
                        }
                
        

return 0;
}