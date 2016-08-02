#include<cstdio>

int main ()
{
    int T,a,b;
    long long ans;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &a, &b);
        ans = a * b * 2;
        if(ans >= 0)
            printf("%lld\n", ans);
        else
            printf("%lld\n", (-1) * ans);
    }
    return 0;
}
