#include<cstdio>
#include<string.h>
#include<algorithm>

int main ()
{
    int n, k, ans;
    char map[105][105];
    int a[105], come[105], vis[105];
    while(~scanf("%d", &n))
    {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", map[i]);
        }
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }
        ans = 0;
        while(1)
        {
            k = 0;
            for(int i = 0; i < n; i ++)
            {
                if(!vis[i] && !a[i])
                {
                    k = 1;
                    vis[i] = 1;
                    come[ans ++] = i + 1;
                    for(int j = 0; j < n; j ++)
                    {
                        if(map[i][j] == '1')
                            a[j] --;
                    }
                }
            }
            if(!k)
                break;
        }
        std::sort(come, come + ans);
        printf("%d\n", ans);
        for(int i = 0; i < ans; i ++)
            printf("%d ", come[i]);
        printf("\n");
    }
}
