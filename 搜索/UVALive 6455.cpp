#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;

int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};
int in[5], ans[10][10], graph[104][104], has[105][105];
int x[100], y[100];
char c[105][105];
int fans;

void dfs(int x, int y, int n, int m)
{
    if(x < 1 || x > n || y < 0 || y > m || c[x][y] == '#' || graph[x][y] == 1)
        return ;
    graph[x][y] = 1;
    for(int i = 0; i < 4; i ++)
    {
        for(int j = 0; j < 4; j ++)
        {
            dfs(x + xx[i], y + yy[i], n, m);
        }
    }
}


queue<int> q;
void bfs(int i, int j, int n, int m)
{
    while(!q.empty())
        q.pop();
    q.push(x[i]);
    q.push(y[i]);
    q.push(0);
    memset(has, 0, sizeof(has));
    while(!q.empty())
    {
        int sx = q.front();
        q.pop();
        int sy = q.front();
        q.pop();
        int d = q.front();
        q.pop();

        for(int k = 0; k < 4; k ++)
        {
            if(sx + xx[k] > n || sx + xx[k] < 1 || sy + yy[k] > m || sy + yy[k] < 1)
                continue;
            if(has[sx + xx[k]][sy + yy[k]] || c[sx + xx[k]][sy + yy[k]] == '#')
                continue;
            has[sx + xx[k]][sy + yy[k]] = 1;
            if(sx + xx[k] == x[j] && sy + yy[k] == y[j])
            {
                ans[i][j] = d + 1;
                return ;
            }
            q.push(sx + xx[k]);
            q.push(sy + yy[k]);
            q.push(d + 1);
        }
    }
}

void dfs2(int now, int total, int re, int k)
{
    if(total == 0)
    {
        fans = min(fans, re);
        return ;
    }
    for(int i = 1; i <= k; i ++)
    {
        if(in[i])
            continue;
        in[i] = 1;
        dfs2(i, total - 1, re + ans[now][i], k);
        in[i] = 0;
    }
}

int main()
{
    int n, m;
    while(~scanf("%d %d", &n, &m) && (n || m))
    {
        for(int i = 1; i <= n; i ++)
        {
            scanf("%s", (c[i] + 1));
            for(int j = 1; j <= m; j ++)
            {
                if(c[i][j] == '@')
                {
                    x[0] = i;
                    y[0] = j;
                }
            }
        }

        memset(graph, 0, sizeof(graph));
        dfs(x[0], y[0], n, m);

        int flag = 1, k;
        scanf("%d", &k);
        for(int i = 1; i <= k; i ++)
        {
            scanf("%d %d", &x[i], &y[i]);
            if(graph[x[i]][y[i]] == 0)
                flag = 0;
        }
        if(!flag)
        {
            printf("-1\n");
            continue;
        }

        for(int i = 0; i <= k; i ++)
        {
            for(int j = 0; j <= k; j ++)
            {
                if(i == j)
                    continue;
                bfs(i, j, n, m);
            }
        }

        fans = 0x3ffffff;
        memset(in, 0, sizeof(in));
        dfs2(0, k, 0, k);

        printf("%d\n", fans);
    }
}
