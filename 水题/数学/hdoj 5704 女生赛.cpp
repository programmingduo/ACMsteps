#include<cstdio>
#include<string.h>

int all[106];

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        memset(all, 0, sizeof(all));
        int total = 0, x;
        scanf("%d", &n);
        for(int i = 1; i < n; i ++)
        {
            scanf("%d", &x);
            all[x] ++;
            total += x;
        }
        int ans = (2 * total) / (3 * n - 2);
        printf("%d %.2lf\n", ans, 1.0 / (all[ans] + 1));
    }
    return 0;
}
