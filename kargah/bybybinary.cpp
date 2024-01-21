#include <iostream>
#include <string.h>
using namespace std;
string generatestring(){
    string result="1";
for (int i=1;i<20;i++){
    string complement;
    for (char c:result){
        if (c=='1')
            complement+='0';
        else 
            complement+='1';
    }
    result+=complement;
}
return result;
}
void print(const string &str,int L,int R){
for (int k=L-1;k<R;k++){
    cout<<str[k];
}
}
int main(){
int L,R;
cin>>L>>R;
print(generatestring(),L,R);


}
