#include<cstdio>
#include<queue>
#include<string.h>
#include<map>
#include<set>
using namespace std;

struct EDGE
{
    int x, next;
}edge[100006];
set<int> s;
int head[100005], dep[100005], ch[100005], co[100005];
int all;
void add_edge(int x, int y)
{
    edge[all].x = x;
    edge[all].next = head[y];
    head[y] = all ++;
    edge[all].x = y;
    edge[all].next = head[x];
    head[x] = all ++;
}

void bfs()
{
    dep[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].x;
            if(dep[v])
                continue;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
}

void dfs(int u)
{
    s.insert(co[u]);
    if(ch[u])
        return ;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        if(dep[edge[i].x] == dep[u] + 1)
        {
            dfs(edge[i].x);
        }
    }
}

int query(int u)
{
    int v = u;
    while(!ch[v])
    {
        for(int i = head[v]; i != -1; i = edge[i].next)
        {
            v = -1;
            if(dep[edge[i].x] == dep[v] - 1)
            {
                v = edge[i].x;
                break;
            }
        }
        if(v == -1)
            break;
    }
    if(v != -1)
        return 1;

    s.clear();
    dfs(u);
    return s.size();

}

int main()
{
    int T, n, node, color;
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        printf("Case #%d:\n", t);
        memset(head, -1, sizeof(head));
        memset(dep, 0, sizeof(dep));
        memset(ch, 0, sizeof(ch));
        all = 0;
        scanf("%d", &n);
        int temp = n - 1, x, y, q;
        while(temp --)
        {
            scanf("%d %d", &x, &y);
            add_edge(x, y);
        }
        bfs();

        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &temp);
            co[i] = temp;
        }

        scanf("%d", &q);
        while(q --)
        {
            int op;
            scanf("%d", &op);
            if(op)
            {
                scanf("%d", &temp);
                printf("%d\n", query(temp));
            }
            else
            {
                scanf("%d %d", &node, &color);
                ch[node] = 1;
                co[node] = color;
//                change(node, color);
            }
        }
    }
}
