#include<bits/stdc++.h>
using namespace std;
#define ld long double
int main()
{
   int n;
   cout<<"Enter the dimension of matrix\n";
   cin>>n;
   ld mat[n][n];
   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>mat[i][j];
    ld x[n],y[n];
    for(int i=0;i<n;i++)
        x[i]=1;
    ld last=1e9;//arbitary large value
    for(int itr=1;itr<=10;itr++)//only 10 iterations
    {
        ld mxx=-1e9;    //take as -infinity
        for(int i=0;i<n;i++)
        {
            y[i]=0;
            for(int k=0;k<n;k++)
            {
                y[i]+=mat[i][k]*x[k];
            }
            if(mxx<y[i])
                mxx=y[i];
        }
        if(fabs(mxx-last)<1e-6)
            break;
        last=mxx;
        for(int i=0;i<n;i++)
            x[i]=y[i]/mxx;

    }
    printf("Eigen value is %.6Lf\nEigen vector is:\n",last);
    for(int i=0;i<n;i++)
        printf("%.6Lf\n",x[i]);
   return 0;
}
/*
1st I/P:-
2
4 -5
2 3

Eigen value is 4.051778
Eigen vector is:
-0.714857
1.000000

2nd I/P:-
2
1 -5
-3 -1

Eigen value is -4.000000
Eigen vector is:
1.000000
1.000000

3rd I/P:-

3
2 -1 0
-1 2 -1
0 -1 2

Eigen value is 3.414211
Eigen vector is:
1.000000
-1.414213
1.000000
*/ 