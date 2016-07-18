#include<cstdio>
#include<cmath>

int main ()
{
    int T;
    double y;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%lf", &y);
        double first = 0, last = 100;
        if(y < 6 || y > 807020306)
        {
            printf("No solution!\n");
            continue;
        }
        while(last - first > 1e-6)
        {
            double x = (first + last) / 2;
            if(y - ((((8*x+7)*x+2)*x+3)*x+6) > 1e-6)
                first = x;
            else
                last = x;
        }
        printf("%.4lf\n", last);
    }
    return 0;
}
