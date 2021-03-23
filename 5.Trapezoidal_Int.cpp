#include<bits/stdc++.h>
using namespace std;
double f1(double x)
{
    return 1/(16+x*x);
}
double f2(double x)
{
    return 300*x/(1+exp(x));
}
double f3(double x)
{
    return sqrt(x);
}
void trapezoidal()
{
    double start,end;
    int step;
    cin>>start>>end>>step;
    double h =  (end-start)/step;
    double s = f1(start)+f1(end); 
  
    
    for (int i = 1; i < step; i++) 
        s += 2*f1(start+i*h);

    s*=(h/2);
    printf("%.8lf\n",s);
}
void trapezoidal2()
{
    double start,end;
    int step;
    cin>>start>>end>>step;
    double h =  (end-start)/step;
    double s = f2(start)+f2(end); 
  
    
    for (int i = 1; i < step; i++) 
        s += 2*f2(start+i*h); 
     
    s*=(h/2);
    printf("%.8lf\n",s);
}
void trapezoidal3()
{
    double start,end;
    int step;
    cin>>start>>end>>step;
    double h =  (end-start)/step;
    double s = f3(start)+f3(end); 
  
    
    for (int i = 1; i < step; i++) 
        s += 2*f3(start+i*h); 
     
    s*=(h/2);
    printf("%.8lf\n",s);
}
int main()
{
    trapezoidal();
    trapezoidal2();
    trapezoidal3();
    return 0;
}

/*

IP:-
0 2 6
0 10 20
0 4 4

OP:-
0.11581925
243.46274824
5.14626437
*/