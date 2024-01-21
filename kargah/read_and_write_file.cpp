#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

int main() {
FILE *writefile;
writefile=fopen("d:\\file\\goodby.txt","w");
fputs("goodby brooo",writefile);
fclose(writefile);
FILE *appendfile;
appendfile=fopen("d:\\file\\goodby.txt","a");
fputs("\n cosenanat",appendfile);
fclose(appendfile);
FILE *readfile;
readfile=fopen("d:\\file\\salam.txt","r");
char str[100];
fgets(str,99,readfile);
cout<<str;
fclose(readfile);


  
}