#include <stdio.h>
#include <math.h>
void degrees_triangle(double a,double b,double c){
double pi=3.14159265359;
double x1=acos((b*b +c*c -a*a)/(2*b*c))*(180/pi);
double x2=acos((b*b +a*a- c*c )/(a*b*2))*(180/pi);
double x3=acos((a*a + c*c - b*b)/(a*c*2))*(180/pi);
if (x1>x2){
    double temp=x1;
    x1=x2;
    x2=temp;
}

if (x1>x3){
    double temp=x1;
    x1=x3;
    x3=temp;
}
if (x2>x3){
double temp=x2;
x2=x3;
x3=temp;}
printf("%.2lf %.2lf %.2lf",x1,x2,x3);
}