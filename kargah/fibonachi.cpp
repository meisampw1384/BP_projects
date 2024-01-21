//
// Created by RSKALA on 9/29/2023.
//
#include <iostream>
using namespace std;

int fibonachi(int n){
if (n==1 || n==0){
    return 1;
}
return fibonachi(n-1)+fibonachi(n-2);
}





int main(){
int n;
cin>>n;
n=n-1;
cout<<fibonachi(n);



}
