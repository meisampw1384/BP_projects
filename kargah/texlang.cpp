#include <iostream>
#include <string.h>
using namespace std;

int main(){
char aval[100];
char dovom[100];
char sevom[100];
cin>>aval;
cin>>dovom;
cin>>sevom;
int len=strlen(aval);
int i;
char emtehan_reshte[5];
for (i=0;i<len;i+=5){
    if (aval[i]=='*'&&aval[i+1]=='*'&&aval[i+2]=='*'&&aval[i+3]=='*'&&aval[i+4]=='*'){
        cout<<'T';
    }
    if (aval[i]=='*'&&aval[i+4]=='*'&&dovom[i]=='*'&&dovom[i+2]=='*'&&dovom[i+4]=='*'&&sevom[i]=='*'&&sevom[i+4]=='*'&&aval[i+1]=='o'){
        cout<<'N';
    }
    if (aval[i]=='*'&&aval[i+1]=='*'&&aval[i+3]=='*'&&aval[i+4]=='*'&&dovom[i]=='*'&&dovom[i+2]=='*'&&dovom[i+4]=='*'){
        cout<<'M';
    }
    if (aval[i+2]=='*'&&dovom[i+2]=='*'&&dovom[i+3]=='*'){
        cout<<'A';
    }
    if (aval[i]=='*'&&aval[i+4]=='*'&&dovom[i+2]=='*'&&sevom[i]=='*'&&sevom[i+4]=='*'&&dovom[i]=='o'){
        cout<<'X';
    }
}



}
