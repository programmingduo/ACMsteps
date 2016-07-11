#include<cstdio>

using namespace std;

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        long long n, m, z, l;
        scanf("%lld %lld %lld %lld", &n, &m, &z, &l);
        long long a = 0,ans = 0;
        for(int i = 1; i < n; i ++)
        {
            a = (a * m + z) % l;
            ans = ans ^ (a * 2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
