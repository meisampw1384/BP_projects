#include <stdio.h>

int main(){
<<<<<<< HEAD
    int n;
    int m;
    int c=1;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            printf("%d ",c);
            c++;
        }
        printf("\n");
    }
}
=======
int n,m;
int c=0;
int h;
scanf("%d %d",&n,&m);
for (int i=1;i<=n;i++){
    if (i%2==0){
        for (int j=i*m;j>=(i-1)*m+1;j--)
        printf("%d ",j);
    }
    else {
        for (int j=(i-1)*m + 1;j<=i*m;j++)
            printf("%d ",j);
    }

    printf("\n");  

}
}
>>>>>>> practice
