#include<cstdio>
#include<string.h>

int max(int a, int b)
{
    return a > b? a: b;
}

int main ()
{
    int T, n, x, total, desk;
    scanf("%d", &T);
    for(int t = 1; t <= T;t ++)
    {
        int maxx = -1;
        total = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &x);
            total += x;
            maxx = max(x, maxx);
        }
        int ans;
        if(maxx <= desk / 2)
            printf("Case #%d: %d\n", t, total);
        else
        {
            int temp = (total - maxx) * 2 + 1;
            if(total - temp > temp)
                ans = temp;
            else
                ans = total / 2;
            printf("Case #%d: %d\n", t, ans);
        }
    }
}
