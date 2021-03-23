#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pi acosl(-1.0l)
ld u[50][50];
#define xi x0+(i-1)*h
#define yj y0+(j-1)*h
ld lower(ld x)  //drichlet condn
{
    return 500;
}
ld upper(ld x)  //drichlet condn
{
    return 0;
}
ld left(ld y)   //drichlet condn
{
    return 500;
}
ld right(ld y)  //drichlet condn
{
    return 0;
}                                                 //    |--> this represents partial derivative at left boundary      
ld qleft(ld y)  //in robin boundary conditon if  (∂y/∂x)(a,y) + q(y).u(a,y) = r(y)
{
    return 0;
}
ld rleft(ld y)
{
    return 0;
}
ld qright(ld y) //right boundary(robin boundary can be easily converted to neuman case by takin q=0)
{
    return 0;
}
ld rright(ld y)
{
    return 0;
}
ld qlower(ld x) //lower boundary
{
    return 0;
}
ld rlower(ld x)
{
    return 0;
}
ld qupper(ld x) //upper boundary
{
    return 10;
}
ld rupper(ld x)
{
    return 3000;
}
ld fx(ld x,ld y)
{
    return 0;
}
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
ld h; //the parameter in equation
ld w=1.4; //ω the parameter for SOR relaxation
void update(int i,int j,ld &x0,ld &y0)
{
    ld last=u[i][j];
    u[i][j]=0;
    for(int k=0;k<4;k++)
        u[i][j]+=u[i+dx[k]][j+dy[k]];
    u[i][j]-=h*h*fx(xi,yj);
    u[i][j]/=4;
    u[i][j]=w*u[i][j]-(w-1)*last;   //SOR relaxation
}
void robin_update(int i,int j,ld x0,ld y0,ld q,ld r)    //when mixed condn is given
{
    ld c=(4+2*h*q),last=u[i][j];
    u[i][j]=0;
    for(int k=0;k<4;k++)
        u[i][j]+=u[i+dx[k]][j+dy[k]];
    u[i][j]-=h*h*fx(xi,yj);
    u[i][j]/=c;
    u[i][j]=w*u[i][j]-(w-1)*last;   //SOR relaxation
}
int main()
{
    int n=3;
    int m=5;
    ld x0=0,xn=1./2,y0=0,ym=1;
    h=(xn-x0)/(n-1);
//left boundary update(drichlet)
    for(int j=1;j<=m;j++)
        u[1][j]=left(yj);
//right boundary update
    // for(int j=1;j<=m;j++)
    //     u[n][j]=right(yj);
//lower boundary update
    for(int i=1;i<=n;i++)
        u[i][1]=lower(xi);
//upper boundary update
    // for(int i=1;i<=n;i++)
    //     u[i][m]=upper(xi);
    
    for(int itr=0;itr<15;itr++)
    {
//now update inner mesh values
        for(int j=2;j<m;j++)
            for(int i=2;i<n;i++)
                update(i,j,x0,y0);
//left boundary update(if mixed or newman) Fictious node
        // for(int j=1;j<=m;j++)
        //     u[0][j]=rleft(yj)*2*h+u[2][j];
        // for(int j=2;j<m;j++)
        // {
        //     int i=1;
        //     robin_update(i,j,x0,y0,qleft(yj),rleft(yj));
        // }
//right boundary update
        for(int j=1;j<=m;j++)
            u[n+1][j]=rright(yj)*2*h+u[n-1][j];
        for(int j=2;j<m;j++)
        {
            int i=n;
            robin_update(i,j,x0,y0,qright(yj),rright(yj));
        }
//lower boundary update
        // for(int i=1;i<=n;i++)
        //     u[i][0]=rlower(xi)*2*h+u[i][2];
        // for(int i=2;i<n;i++)
        // {
        //     int j=1;
        //     robin_update(i,j,x0,y0,qlower(xi),rlower(xi));
        // }
//upper boundary update
        for(int i=1;i<=n;i++)
            u[i][m+1]=rupper(xi)*2*h+u[i][m-1];
        for(int i=2;i<n;i++)
        {
            int j=m;
            robin_update(i,j,x0,y0,qupper(xi),rupper(xi));
        }
//incase of more than one mixed boundary conditions their meeting corner will also have fictious points,update them 

//upper right corner 
         robin_update(n,m,x0,y0,qupper(xn),rupper(xn));
//lower right corner
         //robin_update(n,1,x0,y0,qlower(xn),rlower(xn));   //change q and r accorind to robon condtion is given on which side
//lower left corner
         // robin_update(1,1,x0,y0,qleft(y0),rleft(y0));
//upper left corner
         // robin_update(1,m,x0,y0,qupper(x0),rupper(x0));


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
