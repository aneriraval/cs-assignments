#include<stdio.h>
#include <string.h>
int main()
{
    int N,max=0,temp,len;
 printf("Enter number of players:\n");
 scanf ("%d",&N);
 char Name[N][20];
 char rname[20],nname[20];
 int Score[N];
 for (int i=0;i<N;i++){
     printf ("Enter Name and Runs for Player %d:\n",i+1);
    scanf("%s %d", Name[i], &Score[i]); 
 }
for (int i=0;i<N;i++){
    if (Score[i]>max){
        max=Score[i];
        temp=i;
    }
}
len=strlen (Name[temp]);
printf("Top scorer: %s (%d runs)\n",Name[temp],Score[temp]);
strcat(Name[temp],(" (MVP) "));
printf ("Name length: %d\n",len);
printf("Enter a player's name to replace:\n");
scanf("%s",rname);
printf("Enter new name:\n");
scanf("%s",nname);
for (int i=0;i<N;i++){
    if (strcmp(Name[i],rname)==0){
        strcpy(Name[i],nname);
    }
}
printf ("\nUpdated Player list:\n");
for (int i=0;i<N;i++){
    printf("%s %d\n",Name[i],Score[i]);
}
return 0;
}
