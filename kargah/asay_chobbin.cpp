#include <iostream>
using namespace std;

int main(){
int x;
cin>>x;
   int a,b,c=0;
    if (x%2==0){
        for (int a=x/2-1;a>=x/3;a--){
            for (int b=a;b>=(x-a-b);b--){
                c++;
            }
        }
    }
    else 
    for (int a=x/2;a>=x/3;a-- ){
         for (int b=a;b>=(x-a-b);b--){
                c++;
            }
    }
    cout<<c;

    return 0;
}


