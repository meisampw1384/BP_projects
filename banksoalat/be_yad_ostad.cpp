#include <iostream> 
using namespace std;



int main(){
int m,n;    
cin>>n>>m;
int array[n][m];
for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
        cin>>array[i][j];
    }
}
for (int i=0;i<n;i++){
    for (int j=1;j<m;j++){
        if (array[i][0]==array[i][j]){
            swap(array[i][j],array[i+1][j]);
        }
    }
}
for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
        cout<<array[i][j]<<" ";
    }
    cout<<endl;
}







    return 0;
}
    

