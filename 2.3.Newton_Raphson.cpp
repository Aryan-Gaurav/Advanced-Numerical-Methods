#include<bits/stdc++.h>
using namespace std;
double fx(double x)
{
    return 3*x-cos(x)-1;
}
double f1x(double x)
{
    return 3+sin(x);
}
int main()
{
    double x0,x1,d=1e-5;
    cout<<"Enter the intial guess\n";
    cin>>x0;
    int n;
    cout<<"Enter the number of iterations\n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(fabs(f1x(x0))<d) //slope is too low for updation
            break;
        x1=x0-fx(x0)/f1x(x0);
        if(fabs((x1-x0)/x1)<1e-5)   //relative difference is low i.e. converged
            break;
        else x0=x1;
    }
    printf("%.6lf",x0);
    return 0;
}
/*
Input is
1.5
100
*/
