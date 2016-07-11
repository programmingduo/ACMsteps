#include<cstdio>

long long multi(long long a, long long b, long long mod)
{
    long long ret;
    ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret  = ret * a % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return ret;
}

int main ()
{
    long long a, b;
    while(~scanf("%lld%lld", &a, &b))
    {
        if(b == 1)
        {
            printf("1\n");
            continue;
        }
        long long ans = multi(2, b, 1000000007);
        ans --;
        ans = multi(ans , a, 1000000007);
        printf("%lld\n", ans);
    }
    return 0;
}
