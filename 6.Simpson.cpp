#include<bits/stdc++.h>
using namespace std;
double f1x(double x)
{
    return 1/(1+x);
}
double f2x(double x)
{
    return exp(x*x);
}
double f3x(double x)
{
    return sin(x);
}
void intergral1()
{
    double x0=2,x1=3;
    int n=4;//always even
    double h=(x1-x0)/n;
    double sum=0;
    while(x0<x1)
    {
        sum+=(h/3)*(f1x(x0)+4*f1x(x0+h)+f1x(x0+2*h));
        x0+=2*h;
    }
    printf("The value of integral is %.6lf\n",sum);
}
void intergral2()
{
    double x0=0,x1=1;
    int n=4;
    double h=(x1-x0)/n;
    double sum=0;
    while(x0<x1)
    {
        sum+=(h/3)*(f2x(x0)+4*f2x(x0+h)+f2x(x0+2*h));
        x0+=2*h;
    }
    printf("The value of integral is %.6lf\n",sum);
}
void intergral3()
{
    double x0=0,x1=M_PI/2;
    int n=12;
    double h=(x1-x0)/n;
    double sum=0;
    while(x0<x1)
    {
        sum+=(h/3)*(f3x(x0)+4*f3x(x0+h)+f3x(x0+2*h));
        x0+=2*h;
    }
    printf("The value of integral is %.6lf\n",sum);
}
int main()
{
   intergral1();
   intergral2();
   intergral3();
}   
/*
OUTPUT:-
The value of integral is 0.287683
The value of integral is 1.463711
The value of integral is 1.000003
*/