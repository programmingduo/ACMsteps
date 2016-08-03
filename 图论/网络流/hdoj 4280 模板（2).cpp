#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;

int min(int a, int b)
{
    return a<b? a: b;
}

const int inf = 0x3fffffff;
const int ver = 1000005, edg = 1000005;
int top;
int head[ver], d[ver], gap[edg], pre[edg];
struct Edge
{
    int v, next;
    int c, f;
}edges[edg];

struct Iasp
{


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

    int sap(int s, int t)
    {
        set_d(t);
        int ans = 0, u = s;
        int flow = inf;
        while(d[s] <= top)
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
//                        printf("%d ", flow);
                        flow = inf;
                    }
                    break;
                }
            }
            if(i == -1)
            {
                if(--gap[d[u]] == 0)
                    break;

                int dmin = t;
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
}Sap;

int main ()
{
    int T, n, m, x, y, a, c, b, s, t;
    scanf("%d", &T);
    while(T --)
    {
        Sap.init();
        scanf("%d %d", &n, &m);
        int sx = 1000005, tx = -1000005;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d %d", &x, &y);
            if(sx > x)
            {
                s = i + 1;
                sx = x;
            }
            if(tx < x)
            {
                t = i + 1;
                tx = x;
            }
        }
//        printf("%d %d\n", s, t);
        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d %d", &a, &b, &c);
            Sap.add(a, b, c);
            Sap.add(b, a, c);
        }
        int ans = Sap.sap(s, t);
        printf("%d\n", ans);
    }
    return 0;
}
