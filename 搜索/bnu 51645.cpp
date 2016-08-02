#include<cstdio>
#include<string.h>

int minn, m, n, vis[2008];

struct node{
    int l, r;
}edge[2006];

void dfs(int x, int step)
{
    if(step >= minn)
        return ;
    if(x == m)
    {
        minn = step;
        return ;
    }

    if(vis[edge[x].l] || vis[edge[x].r])
    {
        dfs(x +1, step);
        return ;
    }

    vis[edge[x].l] = 1;
    dfs(x + 1, step + 1);
    vis[edge[x].l] = 0;

    vis[edge[x].r] = 1;
    dfs(x +1, step+1);
    vis[edge[x].r] = 0;

}


int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        memset(vis, 0, sizeof(vis));
        minn = 11;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%d", &edge[i].l, &edge[i].r);
        }
        dfs(0, 0);
        if(minn <= 10)
            printf("%d\n", minn);
        else
            printf("GG\n");
    }
}
