#include <stdio.h>

int main(){
int n;
scanf("%d",&n);
for(int i=0;i<=n;i++){
    for (int r=1;r<=n-i;r++)
      printf(" ");
    for (int j=1;j<=2*i+1;j++){
        printf("*");
    }
    printf("\n");

}
for (int i=1;i<=n;i++){
  for (int r=1;r<=i;r++){
    printf(" ");
  }
  for (int j=1;j<=2*(n-i)+1;j++){
    printf("*");
  }
  printf("\n");
}

}