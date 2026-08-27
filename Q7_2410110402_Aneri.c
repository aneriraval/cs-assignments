
#include <stdio.h>
//Aneri Raval 2410110402
int main()
{
	int ones, twos, fives, tens, fifties, hundreds,N;
	printf("Please enter the amount (Rs N)\n");
	scanf("%d",&N);
	if (N<2)
	{
		printf("%d can be given as %d Rs 1 note(s)\n The total number of notes = %d\n",N,N,N);
	}
	else if (N<5) {
		twos=N/2;
		ones=N%2;
		if (N%2==0)
		{
			printf ("%d can be given as %d Rs 2 note(s)\n The total number of notes = %d\n ",N,twos,twos);
		}
		else {
			printf ("%d can be given as %d Rs 2 note(s) and %d Rs 1 note(s)\n The total number of notes = %d\n ",N,twos,ones,twos+ones);
		}
	}
	else if (N<10) {
		fives=N/5;
		twos=(N%5)/2;
		ones=(N%5)%2;
		if ((N%5)==0)
		{
			printf ("%d can be given as %d Rs 5 note(s)\n The total number of notes = %d\n",N,fives,fives);
		}
		else if (ones==0)
		{
			printf ("%d can be given as %d Rs 5 note(s) and %d Rs 2 note(s)\n The total number of notes = %d\n",N,fives,twos,fives+twos);
		}
		else {
			printf ("%d can be given as %d Rs 5 note(s), %d Rs 2 note(s) and %d Rs 1 note(s)\nThe total number of notes = %d\n", N,fives,twos,ones,fives+twos+ones);
		}
	}
	else if (N<50) {
		tens=N/10;
		fives=(N%10)/5;
		twos=((N%10)%5)/2;
		ones=((N%10)%5)%2;
		if (N%10==0)
		{
			printf("%d can be given as %d Rs 10 note(s)\nThe total number of notes = %d\n",N,tens,tens);
		}
		else if (N%10%5==0)
		{
			printf("%d can be given as %d Rs 10 note(s) and %d Rs 5 note(s)\nThe total number of notes = %d\n",N,tens,fives,tens+fives);
		}
		else if (ones==0)
		{
			printf("%d can be given as %d Rs 10 note(s), %d Rs 5 note(s) and %d Rs 2 note(s)\nThe total number of notes = %d\n",N,tens,fives,twos,tens+fives+twos);
		}
		else {
			printf("%d can be given as %d Rs 10 note(s), %d Rs 5 note(s), %d Rs 2 note(s) and %d Rs 1 note(s) \nThe total number of notes = %d\n",N,tens,fives,twos,ones,tens+fives+twos+ones);
		}
	}
	else if (N<100){
	   fifties=N/50;
	   tens=(N%50)/10;
	   fives=((N%50)%10)/5;
	   twos=(((N%50)%10)%5)/2;
	   ones= ((((N%50)%10)%5)%2);
	   if (N%50==0){
	       printf("%d can be given as %d Rs 50 note(s)\nThe total number of notes = %d\n",N,fifties,fifties);
	   }
	   else if(N%50%10==0){
	       printf("%d can be given as %d Rs 50 note(s) and %d Rs 10 note(s)\nThe total number of notes = %d\n",N,fifties,tens,fifties+tens);
	   }
	   else if (N%50%10==0){
	       printf("%d can be given as %d Rs 50 note(s), %d Rs 10 note(s) and %d Rs 5 note(s)\nThe total number of notes = %d\n",N,fifties,tens,fives,fifties+tens+fives);
	   }
	   else if (ones==0){
	       printf("%d can be given as %d Rs 50 note(s), %d Rs 10 note(s), %d Rs 5 note(s) and %d Rs 2 note(s)\nThe total number of notes = %d\n",N,fifties,tens,fives,twos,fifties+fives+tens+twos);
	   }
	   else {
	       printf ("%d can be given as %d Rs 50 note(s), %d Rs 10 note(s), %d Rs 5 note(s), %d Rs 2 note(s) and %d Rs 1 note(s)\nThe total number of notes = %d\n,",N,fifties,tens,fives,twos,ones,fifties+tens+fives+twos+ones);
	   }
	}
    else if (N>=100){
       hundreds=N/100;
	   fifties= (N%100)/50;
	   tens=((N%100)%50)/10;
	   fives= (((N%100)%50)%10)/5;
	   twos=((((N%100)%50)%10)%5)/2;
	   ones=(((((N%100)%50)%10)%5)%2);
	   if (N%100==0){
	       printf("%d can be given as %d Rs 100 note(s)\nThe total number of notes = %d\n",N,hundreds,hundreds);
	   }
	   else if (N%100%50==0){
	       printf("%d can be given as %d Rs 100 note(s) and %d Rs 50 note(s)\nThe total number of notes = %d\n",N,hundreds,fifties,hundreds+fifties);
	   }
	   else if (N%100%50%10==0){
	       printf("%d can be given as %d Rs 100 note(s), %d Rs 50 note(s) and %d Rs 10 note(s)\nThe total number of notes = %d\n",N,hundreds,fifties,tens,hundreds+fifties+tens);
	   }
	   else if (N%100%50%10%5==0){
	       printf("%d can be given as %d Rs 100 note(s),%d Rs 50 note(s), %d Rs 10 note(s) and %d Rs 5 note(s)\nThe total number of notes = %d\n",N,hundreds,fifties,tens,fives,hundreds+fifties+tens+fives);
	   }
	   else if (ones==0){
	       printf("%d can be given as %d Rs 100 note(s), %d Rs 50 note(s), %d Rs 10 note(s), %d Rs 5 note(s) and %d Rs 2 note(s)\nThe total number of notes = %d\n",N,hundreds,fifties,tens,fives,twos,hundreds+fifties+tens+fives+twos);
	   }
	   else{
	       printf("%d can be given as %d Rs 100 note(s), %d Rs 50 note(s), %d Rs 10 note(s), %d Rs 5 note(s), %d Rs 2 note(s) and %d Rs 1 note(s)\nThe total number of notes = %d\n",N,hundreds,fifties,tens,fives,twos,ones,hundreds+fifties+tens+fives+twos+ones);
	   }
	   
	}



	return 0;
}