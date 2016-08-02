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
        b /= 2;
    }
    return ret;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        long long a, b;
        a = b = n / 2;
        if(n % 2 != 0)
            b ++;

        long long ans = multi(2, a, 1000000007) * multi(2, b - 1, 1000000007);
        ans %= 1000000007;
        printf("%lld\n", ans - 1);

    }
    return 0;
}
