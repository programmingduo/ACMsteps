#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;

int min(int a, int b)
{
    return a<b? a: b;
}

const int inf = 0x3fffffff;
const int ver = 500, edg = 30000;
struct Iasp
{
    int top;
    int head[ver], d[ver], gap[edg], pre[edg];
    struct Edge
    {
        int v, next;
        int c, f;
    }edges[edg];

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

    //每次加边的时候都要加原边和回边两条边。
    void add(int u, int v, int c)
    {
        add_edge(u, v, c);
        add_edge(v, u, 0);
    }

    //为d数组赋值，求出每个点所在的层次。
    //汇点处于0层
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

    //求此图的最大流
    int sap(int s, int t)
    {
        set_d(t);
        int ans = 0, u = s;
        int flow = inf;

        while(d[s] <= t)
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
                            edges[j^1].f -= flow;
                            u = edges[j ^ 1].v;
                        }
                        ans += flow;
//                        printf("%d\n", flow);
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
                for(int j = head[u];j != -1; j = edges[j].next)
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
    int n, f, d;
    while(~scanf("%d %d %d", &n, &f, &d))
    {
        int s = 0;
        int t = n * 2 + f + d + 1;
        int num = t + 1;
        Sap.init();

        //先建立原点与食物的边，容量为1
        for(int i = 1; i <= f; i ++)
        {
            Sap.add(s, i, 1);
        }
        int temp, food, drink;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d %d", &food, &drink);
            //建立食物与左牛的边，容量为1；
            for(int j = 1; j <= food; j ++)
            {
                scanf("%d", &temp);
                Sap.add(temp, f + i * 2 - 1, 1);
            }

            //建立左牛与优牛的边，容量为1；
            Sap.add(f + i * 2 - 1, f + i * 2, 1);

            //建立右牛与饮料的边，容量为1；
            for(int j = 1; j <= drink; j ++)
            {
                scanf("%d", &temp);
                Sap.add(f+i*2, temp + f+ n*2, 1);
            }
        }

        //建立饮料与汇点的边，容量为1；
        for(int i = 1; i <= d; i ++)
        {
            Sap.add(2*n+f+i, t, 1);
        }

        int ans = Sap.sap(s, t);
        printf("%d\n", ans);
    }
    return 0;
}
