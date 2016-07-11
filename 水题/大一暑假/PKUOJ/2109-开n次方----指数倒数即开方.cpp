#include<cmath>
#include<cstdio>
#include<iostream>

using namespace std;

int main ()
{
    double a, b;
    while(~scanf("%lf%lf", &a, &b))
    {
        cout<< pow(b, 1.0 / a)<< endl;              // G++
        printf("%.0lf\n", pow(b, 1.0 / a));         // C++
    }
    return 0;
}
