#include <cstdio>
#include <algorithm>
#include <string.h>

int ans[17];
int vis[4];

int main ()
{
    int n[4];
    int total, num, flag = 0;

    while(~scanf("%d %d %d %d", &n[0], &n[1], &n[2], &n[3]) && !(n[0] == 0 && n[1] == 0 && n[2] == 0 && n[3] == 0))
    {
        if(flag)
            printf("\n");
        flag = 1;
        memset(vis, 0, sizeof(vis));
        total = 0;
        for(int i = 0; i < 4; i ++)
        {
            vis[i] = 1;
            num = n[i];
            for(int j = 0; j < 4; j ++)
            {
                if(vis[j])
                    continue;
                vis[j] = 1;
                num = num * 10 + n[j];
                for(int k = 0; k < 4; k ++)
                {
                    if(vis[k])
                        continue;
                    vis[k] = 1;
                    num = num * 10 + n[k];
                    if(vis[k])
                        continue;
                    for(int l = 0; l < 4; l ++)
                    {
                        if(vis[l])
                            continue;
                        num = num * 10 + n[l];
                        ans[total ++] = num;
                        num /= 10;
                    }
                    vis[k] = 0;
                    num /= 10;
                }
                vis[j] = 0;
                num /= 10;
            }
            vis[i] = 0;
        }

        std::sort(ans, ans + 16);
        for(int i = 0; i < 16; i ++)
            printf("%d ", ans[i]);
        printf("%d", ans[0]);
        for(int i = 1; i < 16; i ++)
        {
            if(ans[i] == ans[i - 1])
                continue;
            else if(ans[i] / 1000 == ans[i - 1] / 1000)
            {
                printf(" %d", ans[i]);
            }
            else
                printf("\n%d", ans[i]);
        }
    }
}
