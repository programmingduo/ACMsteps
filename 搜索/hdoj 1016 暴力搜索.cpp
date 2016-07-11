#include<cstdio>
#include<string.h>

int prime[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}, ans[25], vis[25];
int len = 11, n;

int isprime(int i)
{
    switch(i)
    {
    case 3:
    case 5:
    case 7:
    case 11:
    case 13:
    case 17:
    case 19:
        return 1;
    default :
        return 0;
    }
}

void dfs(int k)
{
    if(k == n - 1)
    {
        if(isprime(ans[k] + 1))
        {
            for(int i = 0; i < n; i ++)
                if(i)
                    printf("%d ", ans[i]);
                else
                    printf("%d", ans[i]);
                printf("\n");
            return ;
        }
        else
            return ;
    }
    for(int i = 0; i < len; i ++)
    {
        if(ans[k] >= prime[i])
            continue ;
        ans[k + 1] = prime[i] - ans[k];
        if(vis[ans[k + 1]] || ans[k + 1] > n)
            continue;
        vis[ans[k + 1]] = 1;
        dfs(k + 1);
        vis[ans[k + 1]] = 0;
    }
}

int main()
{
    int T = 1;
    while(~scanf("%d", &n))
    {
        memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        ans[0] = 1;
        printf("Case %d:\n", T ++);
        dfs(0);
        printf("\n");
    }
}
