#include <stdio.h>

int sum_of_digits(int n){
    int c=0;
    while (n!=0){
        c+=n%10;
        n/=10;
    }
    return c;
}
int sum_of_primary_number(int n){
    int sum=0;
    int i=2;
    while (n>=2){
        if (n%i==0){
            sum+=i;
        }
        while (n%i==0)
           n=n/i;
        i++;   
    }
  return sum;
}
int function_D(int x){
    for (int i=0;i<x;i++){
        if (x==sum_of_primary_number(i)+sum_of_digits(i)+i){
            return 1 ;
        }
    }
    return 0;
}

int main(){
int t;
scanf("%d",&t);
int a[t];
for (int i=0;i<t;i++){
    scanf("%d",&a[i]);
}
for (int i=0;i<t;i++){
    if (function_D(a[i])){
        printf("Yes\n");
    }
    else 
        printf("No\n");
}



    return 0;
}
