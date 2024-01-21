#include <iostream>
#include <math.h>
using namespace std;
int lenint(int n){
    int len;
    while(n!=0){
        n/=10;
        len++;
    }
    return len;
}
int main(){
    int n;
    cin>>n;
    int len=lenint(n);
    int tavan=pow(10,len-1);
    while (tavan!=0){
        int rimender=(n/tavan)%10;
        tavan/=10;
        cout<<rimender<<":  ";
        for (int i=1;i<=rimender;i++){
                cout<<rimender;
        }
        cout<<endl;
    }
    
    




    return 0;
}