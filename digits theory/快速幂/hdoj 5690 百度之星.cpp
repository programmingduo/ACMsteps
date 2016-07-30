#include<cstdio>

long long multi(long long a, long long b, long long mod)
{
    long long ret;
    ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret = ret * a % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return ret;
}

int main ()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        long long x, c, k;
        long long m;
        scanf("%I64d%I64d%I64d%I64d", &x, &m, &k, &c);
        long long ans;
        ans = multi(10, m, k * 9);
        ans += k * 9 - 1;
        ans = ans % (9 * k);
        ans /= 9;
        ans = (ans * x) % k;
        printf("Case #%d:\n", t);
        if(ans == c)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
