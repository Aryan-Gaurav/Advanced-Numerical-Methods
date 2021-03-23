#include<bits/stdc++.h>
#include<complex>
using namespace std;
#define ld long double
#define point complex<ld>
#define x real()
#define y imag()
point fx(point a)
{
    return a*a*a + point(0,-4)*a*a -point(3,0)*exp(a);
    // return a*a*a*a - point(5.0,0)*a*a*a + point(20.0,0)*a*a - point(40,0)*a + point(60,0);
}
point dfx(point a)
{
    return point(3,0)*a*a - point(3,0)*exp(a) + point(0,-8)*a;
    // return point(4,0)*a*a*a -point(15,0)*a*a +point(40,0)*a - point(40,0);
}
int main()
{
    point x0(0.3,1),x1;
    int n=1;
    // ld a,b;
    // cin>>a>>b;
    // x0.real(a),x0.imag(b);
    // cout<<"Enter the number of iterations\n";
    // cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(abs(dfx(x0))<1e-7) //slope is too low for updation
            break;
        x1=x0-fx(x0)/dfx(x0);
        if(abs((x1-x0)/x1)<1e-7)   //relative difference is low i.e. converged
            break;
        else x0=x1;
    }
    cout<<x0;
    return 0;
}