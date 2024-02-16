#include <iostream>
using namespace std;

int main(){
int n;
cin>>n;
char keyvoon[n];
char nezam[n];
char shirfarhad[n];
char kilid[n];
int s=0,ne=0,k=0;
for (int i=0;i<n;i++){
    if (i%6==0 || i%6==1){
        keyvoon[i]='3';
    }
    else if (i%6==2 || i%6==3){
        keyvoon[i]='1';
    }
    else if (i%6==4 || i%6==5){
        keyvoon[i]='2';
    }
}
for (int i=0;i<n;i++){
    if (i%3==0){
        nezam[i]='1';
    }
    else if (i%3==1){
        nezam[i]='2';        
    }
    else if (i%3==2){
        nezam[i]='3';
    }
}
for (int i=0;i<n;i++){
    if (i%4==0 || i%4==2)
       shirfarhad[i]='2';
       else if (i%4==1){
        shirfarhad[i]='1';
       }
       else if (i%4==3){
        shirfarhad[i]='3';
       }
}

for (int i=0;i<n;i++)
   cin>>kilid[i];

for (int i=0;i<n;i++){
    if (keyvoon[i]==kilid[i]){
        ++k;
    }
    if (nezam[i]==kilid[i]){
        ++ne;
    }    
    if (shirfarhad[i]==kilid[i]){
        ++s;
    }
} 
int max=k;
if (ne>max){
    max=ne;
} if (s>max){
    max=s;
} 
cout<<max<<'\n';
if (k==max)
    cout<<"keyvoon";
 if (ne==max)
    cout<<"\nnezam";
 if (s==max)
    cout<<"\nshir farhad" ;   

}
