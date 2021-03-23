#include<bits/stdc++.h>
using namespace std;
#define n 4
long double v[n+1][n+1];
void takerow(int i)
{
    cout<<"Enter the input of row "<<i<<endl;
    for(int j=1;j<=n;j++)
        cin>>v[i][j];
}
void takecol(int j)
{
    cout<<"Enter the input of column "<<j<<endl;
    for(int i=2;i<n;i++)
        cin>>v[i][j];
}
double fx(double x,double y)
{
    return -10*(x*x+y*y+10);
}
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int main()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            v[i][j]=0;
    takerow(1);
    takerow(n);
    takecol(1);
    takecol(n);
    cout<<"Enter number of iterations\n";
    int itr;
    cin>>itr;
    double x0=0,xn=3,y0=0,yn=3;
    double h=(xn-x0)/(n-1);
    for(int it=0;it<itr;it++)
        for(int i=2;i<n;i++)
            for(int j=2;j<n;j++)
            {
                v[i][j]=0;
                for(int k=0;k<4;k++)
                    v[i][j]+=v[i+dx[k]][j+dy[k]];
                v[i][j]-=h*h*fx(x0+(i-1)*h,y0+(j-1)*h);
                v[i][j]/=4;
            }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
            cout<<v[i][j]<<" ";cout<<endl;
    }
    return 0;
}