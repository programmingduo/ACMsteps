#include <cstdio>
#include <string.h>

const int MAXN = 1000006;
const long long INF = 0x3ffffffffffffff;

int head[MAXN], next[MAXN], to[MAXN], used[MAXN];
int vertex, totalv, m;
long long w[MAXN], d1[MAXN], d2[MAXN];

long long min(long long a, long long b)
{
    return a< b? a: b;
}
long long max(long long a, long long b)
{
    return a> b? a:b ;
}
void dijkstra(int start, long long d[])
{
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= vertex + m; i ++)
        d[i] = INF;
    for(int i = head[start]; i != -1; i = next[i])
    {
        int u = to[i];
        d[u] = w[i];
    }
    used[start] = 1;

    int v;
    while(1)
    {
        v = -1;
        for(int i = 1; i <= vertex + m; i ++)
        {
            if(!used[i] && (v == -1 || d[i] < d[v]))
                v = i;
        }
        if(v == -1)
            break;
        used[v] = 1;
        for(int i = head[v]; i != -1; i = next[i])
        {
            int u = to[i];
            d[u] = min(d[u], d[v] + w[i]);
        }
    }

}

void add_edge(int a, int b, long long dis)
{
    to[totalv] = b;
    next[totalv] = head[a];
    w[totalv] = dis;
    head[a] = totalv ++;

    to[totalv] = a;
    next[totalv] = head[b];
    w[totalv] = dis;
    head[b] = totalv ++;
}

int main ()
{
    int T, tt;
    scanf("%d", &T);
    for(int tt = 1; tt <= T; tt ++)
    {
        scanf("%d %d", &vertex, &m);
        memset(head, -1, sizeof(head));
        totalv = 0;
        int num, x;
        long long dis;
        for(int i = 1; i <= m; i ++)
        {
            scanf("%lld %d", &dis, &num);
            for(int j = 1; j <= num; j ++)
            {
                scanf("%d", &x);
                add_edge(vertex + i, x, dis);
            }
        }

        dijkstra(1, d1);
        dijkstra(vertex, d2);
        long long ans = INF;
        for(int i = 1; i <= vertex; i ++)
        {
            ans = min(max(d1[i], d2[i]), ans);
        }
        if(ans == INF)
        {
            printf("Case #%d: Evil John\n", tt);
        }
        else
        {
            int flag = 0;
            printf("Case #%d: %lld\n", tt, ans / 2);
            for(int i = 1; i <= vertex; i ++)
            {
                if(ans == max(d1[i], d2[i]))
                {
                    if(flag)
                        printf(" ");
                    printf("%d", i);
                    flag = 1;
                }
            }
            printf("\n");
        }
    }
}