#include <stdio.h>

int main(){
int n;
int result;
scanf("%d",&n);
for (int i=n;i!=0;i/=10){
int rimender;
rimender=i%10;
result=result*10 + rimender;
}
if (result==n)
   printf("YES"); 
else 
   printf("NO");     

return 0;
}