#include<cstdio>
#include<string.h>

int dfn[106], vis[105], low[105], head[106], flag[105];
int time, total, ans;

struct node
{
    int to, next;
}edge[10000006];

int min(int a, int b)
{
    return a>b? b: a;
}

void add(int a, int b)
{
    edge[total].to = b;
    edge[total].next = head[a];
    head[a] = total ++;
}

void dfs(int id)
{
    time ++;
    low[id] = dfn[id] = time;
    vis[id] = 1;
    int cnum = 0;

    for(int i = head[id]; i; i = edge[i].next)
    {
        int temp = edge[i].to;
        if(vis[temp])
        {
            low[id] = min(low[id], dfn[temp]);
        }
        else
        {
            cnum++;
            dfs(temp);
            low[id] = min(low[id], low[temp]);
            if(id == 1 && cnum > 1)
                flag[id] = 1;
            if(id != 1 && low[temp] >= dfn[id])
                flag[id] = 1;
        }
    }
}

int main ()
{
    int N, a, b;
    while(~scanf("%d", &N) && N)
    {
        ans = time = 0;
        total = 1;
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
        //head=0表示没有该边。因此edge的下标必须从1开始
        memset(flag, 0, sizeof(flag));

        while(~scanf("%d", &a) && a)
        {
            while(~scanf("%d", &b))
            {
                add(a, b);
                add(b, a);
                if(getchar()=='\n')
                    break;
            }
        }
        dfs(1);

        for(int i = 1; i <= N; i ++)
            ans += flag[i];
        printf("%d\n", ans);
    }
}
