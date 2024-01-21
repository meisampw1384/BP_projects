#include <iostream>
using namespace std;
int non_repetive(int x[], int len, int adad, int index_adad) {
   
    if (index_adad >= 0 && index_adad < len) {
        int c = 0;
        for (int i = 0; i < len; i++) {
            if (x[i] == x[index_adad]) {
                c += 1;
            }
        }
        if (c == 1) {
            return 1;
        } else if (c > 1) {
            return 0;
        }
    }
    return 0;
}


int main(){
int adad[10000];
int shomare_shensaie[10000];
int i=0;
while(true){
cin>>shomare_shensaie[i];
if (shomare_shensaie[i]==-1){
    adad[i]=-1;
    break;
}
cin>>adad[i];
i++;
}
int temp[i+1];
for (int j=0;j<i+1;j++){
    temp[j]=adad[j];
}
for (int k=0;k<i-1;k++){
    int flag=0;
    for (int j=0;j<i-k-1;j++){
        if (temp[j]>temp[j+1]){
            swap(temp[j],temp[j+1]);
            flag=1;
        }
    }
    if (flag==0){
        break;
    }
}
int c=0;
int f=0;
while (true){
    if (temp[c]==temp[c+1]){
        for (;temp[c]==temp[c+1];c++);
    
    c++;}
    else{
        f=temp[c];
        break;

    }
}
if (f==-1){
    cout<<"no one won.";
    return 0;
}

int index_shomar;
int min_adad=1000000000;
int min_shomare_shenasaie=shomare_shensaie[0];
for (int j=0;j<i;j++){
if (min_adad>adad[j]&&non_repetive(adad,i,adad[j],j)){
    min_adad=adad[j];
    min_shomare_shenasaie=shomare_shensaie[j];
    index_shomar=j;
}
}
if (non_repetive(shomare_shensaie,i,min_shomare_shenasaie,index_shomar)){
    cout<<min_shomare_shenasaie<<" won.";
}
else 
    cout<<min_shomare_shenasaie<<" cheated.";




    return 0;
}