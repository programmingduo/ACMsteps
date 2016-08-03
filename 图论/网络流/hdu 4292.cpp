#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;

int min(int a, int b)
{
    return a< b? a: b;
}

const int inf=0x3ffffff;
const int ver = 1000, edg = 500000;
int head[ver], d[ver], gap[edg], pre[edg];
char str[100000];
struct Edge
{
    int v, next, c, f;
}edges[edg];

struct Isap
{
    int top;

    void init()
    {
        memset(d, -1, sizeof(d));
        memset(gap, 0, sizeof(gap));
        memset(head, -1, sizeof(head));
        top = 0;
    }

    void add_edge(int u, int v, int c)
    {
        edges[top].v = v;
        edges[top].c = c;
        edges[top].f = 0;
        edges[top].next = head[u];
        head[u] = top ++;
    }

    void add(int u, int v, int c)
    {
        add_edge(u, v, c);
        add_edge(v, u, 0);
    }

    void set_d(int t)
    {
        queue<int> q;
        d[t] = 0;
        q.push(t);
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            gap[d[v]] ++;
            for(int i = head[v]; i != -1; i = edges[i].next)
            {
                int u = edges[i].v;
                if(d[u] == -1)
                {
                    d[u] = d[v] + 1;
                    q.push(u);
                }
            }
        }
    }

    int Sap(int s, int t)
    {
        set_d(t);
        int ans = 0, u = s;
        int flow = inf;
        while(d[s] < top)
        {
            int i;
            for(i = head[u]; i != -1; i = edges[i].next)
            {
                int v = edges[i].v;
                if(edges[i].c > edges[i].f && d[u] == d[v] + 1)
                {
                    u = v;
                    pre[v] = i;
                    flow = min(flow, edges[i].c - edges[i].f);
                    if(u == t)
                    {
                        while(u != s)
                        {
                            int j = pre[u];
                            edges[j].f += flow;
                            edges[j ^ 1].f -= flow;
                            u = edges[j ^ 1].v;
                        }
                        ans += flow;
                        flow = inf;
                    }
                    break;
                }
            }
            if(i == -1)
            {
                if(-- gap[d[u]] == 0)
                    break;
                int dmin = top;
                for(int j = head[u]; j != -1; j = edges[j].next)
                {
                    if(edges[j].c > edges[j].f)
                        dmin = min(dmin, d[edges[j].v]);
                }
                d[u] = dmin + 1;
                gap[d[u]] ++;
                if(u != s)
                    u = edges[pre[u] ^ 1].v;
            }
        }
        return ans;
    }
}sap;

int main ()
{
    int n, f, d, c;
    while(~scanf("%d %d %d", &n, &f, &d))
    {
        sap.init();
        for(int i = 1; i <= f; i ++)
        {
            scanf("%d", &c);
            sap.add(0, i, c);
        }
        for(int i = 1; i <= d; i ++)
        {
            scanf("%d", &c);
            sap.add(f + n * 2 + i, f + n * 2 + d + 1, c);
        }

        for(int i = 1; i <= n; i ++)
        {
            scanf("%s", str);
            for(int j = 1; j <= f; j ++)
            {
                if(str[j - 1] == 'Y')
                {
                    sap.add(j, f + i, 1);
                }
            }
        }

        for(int i = 1; i <= n; i ++)
        {
            sap.add(f + i, f + n + i, 1);
        }

        for(int i = 1; i <= n; i ++)
        {
            scanf("%s", str);
            for(int j = 1; j <= d; j ++)
            {
                if(str[j - 1] == 'Y')
                {
                    sap.add(f + n + i, f + n * 2 + j, 1);
                }
            }
        }

        printf("%d\n", sap.Sap(0, f + n * 2 + d + 1));
    }
    return 0;
}
