#include<cstdio>

double D, H, h;

double f(double b)
{
    return (D * h - b * H) / (D - b) + b;
}

double SanFen(double l, double r) //’“Õπµ„
{
    while(l < r - 0.0000001)
    {
        double mid  = (l+r)/2;
        double mmid = (mid+r)/2;
        if( f(mid) - f(mmid) > 0.0000001 )
            r = mmid;
        else
            l = mid;
    }
    return f(l) > f(r) ? f(l) : f(r);
}

int main ()
{

    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%lf%lf%lf", &H, &h, &D);
        double ans = SanFen(0, (h / H) * D);
        ans = ans > (h / H) * D ? ans : (h / H) * D;
        printf("%.3lf\n", ans);
    }
    return 0;
}
