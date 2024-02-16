#include <iostream>
using namespace std;
int main(){
char esm[21];
cin>>esm;
int a=1;
for (int i=0;i<21;i++){
    if (esm[i]=='L'||esm[i]=='F'||esm[i]=='D'||esm[i]=='T')
    a=a*2;
}
cout<<a;
}