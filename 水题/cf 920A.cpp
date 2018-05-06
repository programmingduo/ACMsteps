#include <iostream>
#include <cstdio>

int max(int a, int b)
{
    return a> b? a: b;
}

int main ()
{
    int N, n, k;
    scanf("%d", &N);
    while(N --)
    {
        scanf("%d%d", &n, &k);
        int l = 0, ans = 0, t;
        while(k --)
        {
            scanf("%d", &t);
            if(l == 0)
                ans = t;
            else
                ans = max(ans, (t - l + 2) / 2);
            l = t;
        }
        ans = max(ans, n - t + 1);
        printf("%d\n", ans);
    }
    return 0;
}
