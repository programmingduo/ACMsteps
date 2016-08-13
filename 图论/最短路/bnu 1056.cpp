#include<cstdio>
#include<string.h>

int vis[400], a[500], w[400][400];

int main ()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            scanf("%d", &w[i][j]);

    memset(vis, 0, sizeof(vis));
    int pos, ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int maxx = 0x3fffffff;
        for(int j = 1; j <= n; j ++)
            if(!vis[j] && a[j] < maxx)
            {
                pos = j;
                maxx = a[j];
            }

        vis[pos] = 1;
        ans += a[pos];
        for(int j = 1; j <= n; j ++)
            if(!vis[j] && w[pos][j] < a[j])
                a[j] = w[pos][j];
    }
    printf("%d\n", ans);

    return 0;
}
