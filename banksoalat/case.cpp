#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int x,y;
    int r=1;
  for (int i=1;i<=n;i++){
        cin>>x>>y;
        if (x==r)
        r=y;
        else if (y==r)
        r=x;
    }
    cout<<r;



    return 0;

}