//Aneri Raval 2410110402
#include <stdio.h>
#include <string.h>
int compare(char *a,char *b){
    int count=0;
    while (a[count]!='\0' && b[count]!='\0' && a[count]==b[count]){
        count=count + 1;
    }
    return count;
}

void maxmatch (char *arr[], int rows){
    int max=0,index1=-5,index2=-5,match=0,i,j;
    for (i=0;i<rows;i++){
        for (j=i+1;j<rows;j++){
            int match=compare(arr[i],arr[j]);
        
            if (match>max){
            max=match;
            index1=i;
            index2=j;
            }
        }
    }
    if (index1!=-5 && index2!=-5){
        printf ("The best matching pair is %s and %s.\nThey have %d characters in common.\n",arr[index1],arr[index2],max);
    }
    else printf("No matching pairs\n");
    
    
}
int main(){
    printf("How many words would you like to compare?\n");
    int n;
    scanf ("%d",&n);
    char arr[n][100],*ptr[n];
    printf("Please enter the strings\n");
    for (int i=0;i<n;i++){
        scanf("%s",arr[i]);
        ptr[i]=arr[i];
    }
    maxmatch( ptr, n);
    return 0;
}
