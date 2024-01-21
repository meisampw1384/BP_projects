#include <stdio.h>

int main(){
int n;
scanf("%d",&n);
if (n==0){
    printf("error");
    exit(0);
}
int a[n];
for (int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for (int i=0;i<n-1;i++){
    int flag=0;
    for (int j=0;j<n-i-1;j++){
       if (a[j]>a[j+1]){
        flag=1;
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
       }
    }
    if (flag==0){
        break;
    }
}
for (int i=0;i<n;i++){
    printf("%d ",a[i]);
}
}