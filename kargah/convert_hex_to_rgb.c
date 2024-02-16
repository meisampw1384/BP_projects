#include  <stdio.h>

int main(){
int y;
    
    scanf("%x",&y);
    printf("RGB(%d, %d, %d)",(y/(256*256))%256,(y/256)%256,y%256);
    
}