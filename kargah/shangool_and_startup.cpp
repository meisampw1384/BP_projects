#include <iostream>
using namespace std;

int main(){
int x[4];
int khordan[4]={0,0,0,0};
for (int i=0;i<4;i++){
    cin>>x[i];
}
while (x[0]&&x[2]){
    ++khordan[0];
    --x[0];
    if (x[0]==0){
        break;
    }
    ++khordan[1];
    --x[2];
    if (x[2]==0){
        break;
    }
    ++khordan[2];
    --x[0];
    if (x[0]==0){
        break;
    }
    ++khordan[3];
    --x[2];
    if (x[2]==0){
        break;
    }
}
for (int i=0;i<4;i++){
    cout<<khordan[i]<<" ";
}
}