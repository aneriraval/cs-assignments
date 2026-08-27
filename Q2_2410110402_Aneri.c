
#include <stdio.h>
//Aneri Raval 2410110402
int main()
{
//2.i
int color, lime, straw, red, orange;
float white, green, blue, purple, crayon;
color=2;
crayon=-1.3;
straw=1;
red=3;
purple=0.32;
white=color*2.5/purple;
    printf("white = %f\n",white);
//2.ii
green=color/purple;
    printf("green = %f\n",green);
//2.iii
orange=color/red;
    printf("orange = %d\n",orange);
//2.iv
blue=(color+straw)/(crayon+0.3);
    printf("blue = %f\n", blue);
//2.v
lime=(red/color) + red%color;
    printf("lime = %d\n", lime);
//2.vi
purple=straw/red*color;
    printf("purple = %f\n",purple);
return 0;
}