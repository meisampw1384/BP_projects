#include <iostream>
using namespace std;
int main(){
int n;
int m;
cin>>n;
cin>>m;
int array[n][m];
for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
        cin>>array[i][j];
    }
}int ne=0;
for (int i=1;i<n-1;i++){
    for (int j=1;j<m-1;j++){
        if (((array[i][j]>array[i][j+1] && array[i][j]>array[i][j-1])&&(array[i][j]<array[i-1][j]&&array[i][j]<array[i+1][j]))||((array[i][j]<array[i][j+1] && array[i][j]<array[i][j-1])&&(array[i][j]>array[i-1][j]&&array[i][j]>array[i+1][j])))
              ne++;
    }
}
cout<<ne;


}