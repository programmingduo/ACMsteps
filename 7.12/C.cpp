#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>

long long a[10005];

using namespace std;

int main ()
{
    long long  n;
    while(cin>> n)
    {
        for(int i = 0; i < n; i ++)
            cin>> a[i];
        std::sort(a, a + n);
        int flag = 0;
        double x1, x3, x2, maxs = -1;
        int ans;
        for(int i = n - 1; i >= 3; i --)
        {
            if(a[i] > a[i - 1] + a[i - 2] + a[i - 3])
                continue;
            flag = 1;
            x1 = a[i];
            x2 = a[i - 1];
            x3 = a[i - 2] + a[i - 3];
            double cos = (x1 * x1) + (x3 * x3) - (x2 * x2);
            cos = cos / (2 * x1 * x3);
            double t = x1 * cos;
            double h = sqrt(x1 * x1 - t * t);
            double s = x3 * s;
            if(s > maxs)
                ans = i;
        }
        if(!flag)
            printf("-1\n");
        else
            printf("%lld\n", a[ans] + a[ans - 1] + a[ans - 2] + a[ans - 3]);
    }
    return 0;
}
