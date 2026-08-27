//Aneri Raval 2410110402
#include <stdio.h>
int orthogonal(int n,int a[n][n]);
int orthogonal(int n,int a[n][n]){
    int b[n][n], c[n][n],temp=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            b[i][j]=a[j][i];
        }
    } 
    for (int k=0;k<n;k++){
        for (int m=0;m<n;m++){
            c[k][m]=0;
            for (int p=0;p<n;p++){
                c[k][m]=c[k][m]+a[k][p]*b[p][m];
            }
         }
    }
    for (int d=0;d<n;d++){
        for (int e=0;e<n;e++){
            if (d==e){
                if (c[d][e]!=1 && c[d][e]!=-1){
                    temp=0;
                }
            }
            if (d!=e){
                if (c[d][e]!=0){
                    temp=0;
                }
            }
            
        }
    }
    return temp;

}
int main(){
    printf("Please enter the number of rows and columns in the square matrix\n");
    int n,o;
    scanf("%d",&n);
    int (*ortho)(int,int[][n]);
    ortho=&orthogonal;
    int a[n][n];
    printf ("Please enter the values of the matrix (row wise)\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf ("%d",&a[i][j]);
        }
    }
    o=ortho (n,a);
    if (o==1){
        printf ("Matrix is orthogonal\n");
    }
    else printf ("Matrix is not orthogonal\n");
    return 0;
}