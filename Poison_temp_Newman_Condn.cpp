#include<bits/stdc++.h>
using namespace std;
#define ld long double
ld u[100][100];
// void takerow(int i)
// {
//     cout<<"Enter the input of row "<<i<<endl;
//     for(int j=1;j<=n;j++)
//         cin>>v[i][j];
// }
// void takecol(int j)
// {
//     cout<<"Enter the input of column "<<j<<endl;
//     for(int i=2;i<n;i++)
//         cin>>v[i][j];
// }
ld lower(ld x)  //drichlet condn
{
    return 0;
}
ld upper(ld x)  //drichlet condn
{
    return 0;
}
ld left(ld y)   //drichlet condn
{
    return 0;
}
ld right(ld y)  //drichlet condn
{
    return 0;
}
ld low1(ld x,int i,int j)     //newman condn or mixed
{
    return 0;
}
ld up1(ld x,int i,int j)
{
    return 0;
}
ld lef1(ld y,int i,int j)
{
    return 0;
}
ld rig1(ld y,int i,int j)
{
    return 0;
}
ld fx(ld x,ld y)
{
    return -(2+M_PI*M_PI*x*(1-x))*cos(M_PI*y);
}
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
ld h; //the parameter in equation
void update(int i,int j,ld x0,ld y0)
{
    u[i][j]=0;
    for(int k=0;k<4;k++)
        u[i][j]+=u[i+dx[k]][j+dy[k]];
    u[i][j]-=h*h*fx(x0+(i-1)*h,y0+(j-1)*h);
    u[i][j]/=4;
}
int main()
{
    // takerow(1);
    // takerow(n);
    // takecol(1);
    // takecol(n);
    int n=5;
    int m=3;
    int itr=100;
    ld x0=0,xn=1,y0=0,ym=1.0/2;
    h=(xn-x0)/(n-1);
    //left boundary update(drichlet)
    for(int j=1;j<=5;j++)
        u[1][j]=left(y0+(j-1)*h);
    //right boundary update
    for(int j=1;j<=5;j++)
        u[n][j]=right(y0+(j-1)*h);
    // //lower boundary update
    // for(int i=1;i<=n;i++)
    //     u[i][1]=lower(x0+(i-1)*h);
    //upper boundary update
    for(int i=1;i<n;i++)
        u[i][m]=upper(x0+(i-1)*h);
    for(int itr=0;itr<=50;itr++)
    {
            //left boundary update(if mixed or newman) Fictious node
        // for(int j=2;j<m;j++)
        //     u[0][j]=lef1(y0+(j-1)*h,1,j)*2*h+u[2][j];
        // for(int j=2;j<m;j++)
        // {
        //     int i=1;
        //     upadte(i,j,x0,y0);
        // }
            //right boundary update
        // for(int j=2;j<m;j++)
        //     u[n+1][j]=rig1(y0+(j-1)*h,n,j)*2*h+u[n-1][j];
        // for(int j=2;j<m;j++)
        // {
        //     int i=n;
        //     update(i,j,x0,y0);
        // }
            //lower boundary update
        for(int i=2;i<n;i++)
            u[i][0]=low1(x0+(i-1)*h,i,1)*2*h+u[i][2];
        for(int i=2;i<n;i++)
        {
            int j=1;
            update(i,j,x0,y0);
        }
            //upper boundary update
        // for(int i=2;i<n;i++)
        //     u[i][m+1]=up1(x0+(i-1)*h,i,m)*2*h+u[i][m-1];
        // for(int i=2;i<n;i++)
        // {
        //     int j=m;
        //     update(i,j,x0,y0);
        // }
        //noe update inner mesh values
        for(int j=2;j<m;j++)
            for(int i=2;i<n;i++)
                update(i,j,x0,y0);

    }
    //print the answer
    for(int j=m;j>=1;j--)
    {
        for(int i=1;i<=n;i++)
            printf("%.5Lf ",u[i][j]);
        cout<<"\n";
    }
    return 0;
}