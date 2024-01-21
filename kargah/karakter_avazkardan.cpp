#include <iostream>
using namespace std;

int main(){
int n;
cin>>n;
char reshte[n][1000];
for (int i=0;i<n;i++){
    cin>>reshte[i];
}
for (int j=n-1;j>=0;j--){
    cout<<reshte[j]<<" ";
}



}