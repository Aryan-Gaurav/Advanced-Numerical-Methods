#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pi acosl(-1.0)
ld lower(ld x)//u(x,0)
{
    return sin(pi*x)/8;
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
ld u[100][100];
int main()	//Uxx = (c) * Uyy
{
    ld alpha,lambda,x0,xn,t0,tm,h,l,c=1;    //l=Δt and h=Δx
    alpha=1;
    h=0.1,l=0.1;
    x0=0,xn=1;
    t0=0;
    alpha=c*l*l/(h*h);
    int n=10;    //update it manually ld precision cause errors
    for(int i=0;i<=n;i++)
    {
        u[i][0]=lower(x0+i*h);
    }
    for(int j=0;j<10;j++)
    {
        u[0][j]=left(t0+j*l);
        u[n][j]=right(t0+j*l);
    }
    for(int i=1;i<n;i++)
        u[i][1]=((alpha*(u[i-1][0]+u[i+1][0])+2*(1-alpha)*u[i][0]))/2;
    for(int j=2;j<=10;j++)
    {
        for(int i=1;i<n;i++)
        {
            u[i][j]=-u[i][j-2]+alpha*(u[i-1][j-1]+u[i+1][j-1])+2*(1-alpha)*u[i][j-1];
        }
    }
    for(int j=10;j>=0;j--)   //in the form of increasing x in right and increasing t in up direction
    {
        for(int i=0;i<=n;i++)
            printf("%.4Lf ",u[i][j]);
        cout<<"\n";
    }
    return 0;
}
//For more details refer to S.S.Sastry page no. 363 