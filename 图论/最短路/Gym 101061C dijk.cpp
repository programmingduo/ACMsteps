#include<cstdio>
#include<string.h>

const int INF = 0x3fffffff;

int total;
int head[1005], dis[104], disa[105], disb[104];

struct node
{
    int to, w[2], next;
}edge[100005];

void add_edge(int u, int v, int w, int o)
{
    edge[total].to = u;
    edge[total].w[o] = w;
    edge[total].w[o ^ 1] = 0;
    edge[total].next = head[v];
    head[v] = total ++;

    edge[total].to = v;
    edge[total].w[o] = w;
    edge[total].w[o ^ 1] = 0;
    edge[total].next = head[u];
    head[u] = total ++;
}

int min(int a, int b)
{
    return a< b? a: b;
}

int from, to;
void solve(int v)
{

    for(int i = 1; i <= v; i ++)
        dis[i] = 0, disa[i] = INF, disb[i] = INF;
    disa[from] = disb[from] = 0;
//    for(int i = 0; i <= v; i ++)
//        printf("%d ", disa[i]);
//    for(int i = head[from]; i != -1; i = edge[i].next)
//    {
//        int v = edge[i].to;
//        disa[v] = edge[i].w[0];
//        disb[v] = edge[i].w[1];
//    }

    for(int i = 0; i <= v; i ++)
    {
        int m = INF, n = INF, x = -1;
        for(int j = 1; j <= v; j ++)
        {
            if(!dis[j])
            {
                if(disa[j] < m)
                {
                    x = j;
                    m = disa[j];
                    n = disb[j];
                }
                else if(disa[j] == m && disb[j] < n)
                {
                    x = j;
                    n = disb[j];
                }
            }
        }
        if(x == -1)
            break;
        dis[x] = 1;

        for(int j = head[x]; j != -1; j = edge[j].next)
        {
            int a = edge[j].to;
            if(!dis[a])
            {
                int t = m + edge[j].w[0];
//                int y = edge[j].w[0];
                int y = disa[a];
                if(disa[a] > m + edge[j].w[0])
                {
                    disa[a] = m + edge[j].w[0];
                    disb[a] = n + edge[j].w[1];
                }
                else if(disa[a] == m + edge[j].w[0])
                {
                    disb[a] = min(disb[a], n + edge[j].w[1]);
                }
            }
        }
    }
}

int main ()
{
    int T, v, e, u, w, o, vt;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &vt, &e);
        memset(head, -1, sizeof(head));
        total = 0;
        for(int i = 0; i < e; i ++)
        {
            scanf("%d %d %d %d", &u, &v, &w, &o);
            add_edge(u, v, w, o - 1);
        }

        scanf("%d %d", &from, &to);
        if(from == to)
        {
            printf("0\n");
            continue;
        }
        solve(vt);
        if(dis[to])
        {
            printf("%d %d\n", disa[to], disb[to] + disa[to]);
        }
        else
            printf("-1\n");
    }
}
