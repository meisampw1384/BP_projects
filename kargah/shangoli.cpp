#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    int flag=0;
   
    char a[n][5];
        for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        if (a[i][0]=='C'){
            flag=!flag;
            i++;
        }
        if (flag==0){
            cout<<a[i];
        }
        else if (flag==1)
           cout<<(char)toupper(a[i][0]);
        
    }
}