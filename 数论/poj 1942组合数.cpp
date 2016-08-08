#include<cstdio>

inline long long min(long long a, long long b)
{
    return a < b? a : b;
}

inline long long c(long long n, long long m)
{
    double a = 1, b = 1;
    m = min(n - m, m);
    for(long long i = 1; i <= m; i ++)
    {
        a = a * (n - i + 1) / i;
    }
    return a;
}

int main ()
{
    long long a, b;
    while(~scanf("%lld %lld", &a, &b))
    {
        if(a == 0 && b == 0)
            break;
        printf("%lld\n", c(a + b, b));
    }
}
