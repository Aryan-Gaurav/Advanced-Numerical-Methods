#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the nuber of entries\n";
    cin>>n;
    double x[n],y[n];
    cout<<"Enter the values of x\n";
    for(int i=0;i<n;i++)
        cin>>x[i];
    cout<<"Enter the values of y\n";
    for(int i=0;i<n;i++)
        cin>>y[i];
    double a,sum=0;
    cout<<"Enter the value to be evaluated\n";
    cin>>a;
    for(int i=0;i<n;i++)
    {
        double prod=y[i];
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                prod*=(a-x[j])/(x[i]-x[j]);
            }
        }
        sum+=prod;
    }
    printf("%.8lf",sum);
    return 0;
}
/*
Case 1
4
0 1 2 3
1 2.25 3.75 4.25
1.25
Ans:- 2.65039062

Case 2
6
1980 1985 1990 1995 2000 2005
440 510 525 571 500 600
1998

Ans:- 541.57856000

*/