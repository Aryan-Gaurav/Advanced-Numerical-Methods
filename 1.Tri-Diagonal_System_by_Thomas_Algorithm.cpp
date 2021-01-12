#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the size of matrix\n";
    int n;
    cin>>n;
    double a[n],b[n],c[n],d[n],x[n];
    cout<<"Enter sub digonal\n";
    for(int i=0;i<n-1;i++)  //index od a starts from 1 rather than 0
        cin>>a[i+1];
    cout<<"Enter diogonal elements\n";
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<"Enter super diagonal elements\n";
    for(int i=0;i<n-1;i++)
        cin>>c[i];
    cout<<"Enter the value of d\n";
    for(int i=0;i<n;i++)
        cin>>d[i];
    double alpha[n],beta[n];
    alpha[0]=b[0];
    beta[0]=d[0]/b[0];
    for(int i=1;i<n;i++)
    {
        alpha[i] = b[i]-(a[i]*c[i-1])/alpha[i-1];
        beta[i] = (d[i]-a[i]*beta[i-1])/alpha[i];
    }
    x[n-1]=beta[n-1];
    for(int i=n-2;i>=0;i--)
        x[i]=beta[i]-(c[i]*x[i+1])/alpha[i];
    // for(int k=1;k<n;k++)
    // {
    //     double  m =a[k]/b[k-1];
    //     b[k] -= m*c[k-1];
    //     d[k] -= m*d[k-1];
    // }
    // x[n-1] = d[n-1]/b[n-1];
    // for(int i=n-2;i>=0;i--)
    //     x[i] = (d[i]-c[i]*x[i+1])/b[i];
    cout<<"After updating value of x are:\n";
    for(int i=0;i<n;i++)
        cout<<"x"<<i+1<<"="<<x[i]<<endl;
    return 0;
}
