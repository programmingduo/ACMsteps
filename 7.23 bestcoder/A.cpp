#include<cstdio>

int main ()
{
    int T, n, m;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &n, &m);

        int ans = 0;
        while(n && m)
        {
            ans += n&1;
            n >>= 1;
            m --;
        }
        ans += n;
        printf("%d\n", ans);
    }
    return 0;
}
