#include<bits/stdc++.h>
using namespace std;
double f1(double x,double y)
{
    return 6-2*y/x;
}
double f2(double x,double y)
{
    return y*log(y/x);
}
double f3(double x,double y)
{
    return (y-x)/(y+x);
}                                                  //       |---> this function is for dy/dx calulation
void solver(double x0,double xn,double y0,double h,double (*f)(double,double))
{
    double y;
    while(x0<xn)
    {
        y=y0+h*f(x0,y0);
        y0=y;
        x0+=h;
    }
    printf("%.6lf\n",y);
}
//alternate way to define solver is
/*                                                             |-->return type
void solver(double x0,double xn,double y0,double h,function<double(double,double)> f)
*///                                                                |--->arguments
int main()
{
    solver(3,3.5,1,0.1,f1);
    solver(2,2.5,exp(1),0.1,f2);
    solver(0,0.1,1,0.1,f3);
    return 0;
}
/*
Output:-
3.381462
3.106312
1.100000
*/