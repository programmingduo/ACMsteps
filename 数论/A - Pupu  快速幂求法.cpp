#include<cstdio>

using namespace std;


//a是底数，b是指数，mod是取模
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
    long long n;
    while(~scanf("%lld", &n))
    {
        if(n == 0)
            break;
        long long ans = multi(2, n - 1, n);
        ans = (ans + 1) % n;
        printf("%lld\n", ans);
    }

    return 0;
}
