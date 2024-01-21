#include <stdio.h>

int main(){
 long long int x,y;
scanf("%lld %lld",&x,&y);
long long int tempx=x;
long long int tempy=y;
while (y!= 0) {
        long long int temp = y;
        y= x % y;
        x = temp;

}
unsigned long  long int  kmm=(tempx*tempy)/x;
printf("%d %llu",x,kmm);

}