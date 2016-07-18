#include<cstdio>

int main ()
{
    long long n, k;
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%lld%lld", &n, &k);
        if(k * (k + 1) / 2 > n)
        {
            printf("-1\n");
            continue;
        }
        int a = (n - k * (k + 1) / 2) / k;
        int l = (n - k * (k + 1) / 2) % k;
        long long ans = 1;
        for(int i = 1; i <= k; i ++)
        {
            if(k - i < l)
                ans = ans * (a + i + 1) % 1000000007;
            else
                ans = ans * (a + i) % 1000000007;
        }
        printf("%d\n", ans);
    }
    return 0;
}
