#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

double funct(double x)
{
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        double n;
        scanf("%lf",&n);
        if(funct(0)>n || funct(100)<n)
        {
            printf("No solution!\n");
            continue;
        }
        double l = 0.0,r = 100.0;
        double mid = (l+r)/2;
        while(fabs(funct(mid)-n)>1e-5)
        {
            if(funct(mid)>n)
                r = mid;
            else
                l = mid;
            mid = (l+r)/2;
        }
        printf("%.4f\n",mid);
    }

    return 0;
}
