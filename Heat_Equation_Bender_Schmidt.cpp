#include<bits/stdc++.h>
using namespace std;
#define ld long double
ld lower(ld x)//u(x,0)
{
    return 4*x-x*x;
}
ld left(ld t)// u(0,t)
{
    return 0;
}
ld right(ld t)// u(xn,t)
{
    return 0;
}
ld upper(ld x) // u(x,tm)
{
    return 0;
}
int main()
{
    ld alpha,lambda,x0,xn,t0,tm,h,l;    //l=Δt and h=Δx
    alpha=1;
    l=h=1;
    x0=0,xn=4;
    t0=0;
    lambda=alpha*l/(h*h);
    ld u[100][100],temp=0;
    int n=(xn-x0)/h;
    for(int i=0;i<=n;i++)
        u[i][0]=lower(x0+i*h);
    for(int j=0;j<10;j++)
    {
        u[0][j]=left(t0+j*l);
        u[n][j]=right(t0+j*l);
    }
    for(int j=1;j<=10;j++)
    {
        for(int i=1;i<n;i++)
            u[i][j]=(u[i-1][j-1]+u[i+1][j-1])/2;    //Bender-Schmidit formula when λ=1/2
    }
    for(int j=10;j>=0;j--)   //in the form of increasing x in right and increasing t in up direction
    {
        for(int i=0;i<=n;i++)
            printf("%.2Lf ",u[i][j]);
        cout<<"\n";
    }
    return 0;
}