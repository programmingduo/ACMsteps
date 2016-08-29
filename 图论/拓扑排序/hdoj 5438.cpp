#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;

const int maxn = 100055;
int head[maxn], to[maxn], in[maxn], _next[maxn], v[maxn];
long long total, ans, n;

void add_edge(int a, int b)
{
    in[b] ++;
    to[total] = b;
    _next[total] = head[a];
    head[a] = total ++;
}

queue<int> q;
void topo()
{
    while(!q.empty())
        q.pop();
    for(int i = 1; i <= n; i ++)
    {
        if(in[i] < 2)
            q.push(i);
    }
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i = head[t]; i != -1; i = _next[i])
        {
            int u = to[i];
            if(in[u] == 2)
            {
                q.push(u);
            }
            in[u] --;
        }
    }
}

void dfs(int id, long long& tans, long long& tp)
{
    in[id] = 0;
    tans += v[id];
    tp ++;
    for(int i = head[id]; i != -1; i = _next[i])
    {
        int u = to[i];
        if(in[u] < 2)
            continue;
        dfs(u, tans, tp);
    }
}

void dfs()
{
    ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(in[i] > 1)
        {
            long long tp = 0, tans = 0;
            dfs(i, tans, tp);
            if(tp % 2)
                ans += tans;
        }
    }
}

int main ()
{
    int T, m, a, b;
    scanf("%d", &T);
    while(T --)
    {
        memset(head, -1, sizeof(head));
        memset(in, 0, sizeof(in));
        total = 0;
        scanf("%I64d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &v[i]);
        }
        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d", &a, &b);
            add_edge(a, b);
            add_edge(b, a);
        }
        topo();
        dfs();
        printf("%I64d\n", ans);
    }
    return 0;
}
