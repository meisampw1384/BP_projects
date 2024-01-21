#include <iostream>
using namespace std;

int main(){
FILE *file;
file=fopen("shomaresefaresh.bin","wb");
int c=0;
fwrite(&c,sizeof(int),1,file);
fclose(file);




}