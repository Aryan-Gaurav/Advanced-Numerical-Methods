#include<bits/stdc++.h>
using namespace std;
#define ld long double
ld lower(ld x)//u(x,0)
{
    return sin(M_PI*x);
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
int main()
{
    ld alpha,lambda,x0,xn,t0,tm,h,l;    //l=Δt and h=Δx
    alpha=1;
    h=0.2,l=0.02;
    x0=0,xn=1;
    t0=0;
    lambda=alpha*l/(h*h);
    int n=5;    //update it manually ld precision cause errors
    for(int i=0;i<=n;i++)	//intialise all to same values
    {
        for(int j=0;j<=10;j++)
            u[i][j]=lower(x0+i*h);
    }
    for(int j=0;j<10;j++)
    {
        u[0][j]=left(t0+j*l);
        u[n][j]=right(t0+j*l);
    }
    for(int itr=1;itr<=10;itr++)   //Gauss-Sidel iterative based on Crank-Nicolson formula
    {
        for(int j=1;j<=10;j++)
        {
            for(int i=1;i<n;i++)
            {
                ld c=u[i][j-1]+(lambda/2)*(u[i-1][j-1]-2*u[i][j-1]+u[i+1][j-1]);
                u[i][j]=(lambda/(2*(1+lambda)))*(u[i-1][j]+u[i+1][j]) + c/(1+lambda);
            }
        }
    }
    for(int j=10;j>=0;j--)   //in the form of increasing x in right and increasing t in up direction
    {
        for(int i=0;i<=n;i++)
            printf("%.4llf ",u[i][j]);
        cout<<"\n";
    }
    return 0;
}
//For more details refer to S.S.Sastry page no. 363 