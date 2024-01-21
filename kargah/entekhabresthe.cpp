#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char a[20];
    cin>>a;
    if (strcmp("EAST",a)==0){
        cout<<"YES";
    }
    else 
        cout<<"NO";
}