#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;

const int VM = 100010;
const int EM = 400010;
const int inf = 0x3f3f3f3f;
struct E
{
    int to, from, next, cap;
}edge[EM];

int head[VM], cur[VM], dep[VM], gap[VM];
int stack_array[EM];
int e;

void addEdge(int u, int v, int c)
{
    edge[e].from = u;
    edge[e].to = v;
    edge[e].cap = c;
    edge[e].next = head[u];
    head[u] = e ++;

    edge[e].from = v;
    edge[e].to = u;
    edge[e].cap = 0;
    edge[e].next = head[v];
    head[v] = e ++;
}

void sap_init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
}

void get_dep(int t)
{
    gap[0] = 1;
    dep[t] = 0;
    queue<int > q;
    q.push(t);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(edge[i].cap != 0 || dep[v] != -1)
                continue;
            q.push(v);
            gap[dep[v] = dep[u] + 1] ++;
        }
    }
}

int sap(int s, int t)
{
    get_dep(t);
//    printf("1234");
    int ans = 0, u = s, top = 0, flow, neck;
    memcpy(cur, head, sizeof(head));
    while(dep[s] < e)
    {
        if(u == t)
        {
            int flow = inf;
            for(int i = 0; i < top; i ++)
                if(flow > edge[stack_array[i]].cap)
                {
                    flow = edge[stack_array[i]].cap;
                    neck = i;
                }
            for(int i = 0; i < top; i ++)
            {
                edge[stack_array[i]].cap -= flow;
                edge[stack_array[i]^1].cap += flow;
            }
            ans += flow;
            top = neck;
            u = edge[stack_array[top]].from;
        }

//        if(u != t && gap[dep[u] - 1] == 0)
//            break;

        int i;
        for(i = cur[u]; i != -1; i = edge[i].next)
            if(edge[i].cap != 0 && dep[u] == dep[edge[i].to] + 1)
                break;
        if(i != -1)
        {
            cur[u] = i;
            stack_array[top ++] = i;
            u = edge[i].to;
        }
        else
        {
            int dmin = e;
            for(int i = head[u]; i != -1; i = edge[i].next)
            {
                if(edge[i].cap == 0)
                    continue;
                if(dmin > dep[edge[i].to])
                {
                    dmin = dep[edge[i].to];
                    cur[u] = i;
                }
            }
            if(--gap[dep[u]] == 0)
                break;
            gap[dep[u] = dmin + 1] ++;
            if(u != s)
                u = edge[stack_array[--top]].from;
        }
    }
    return ans;
}

int main ()
{
    int T, n, m;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &n, &m);
        int x, y, sx = inf, tx = -inf, s, t, u, v, c;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d %d", &x, &y);
            if(sx > x)
            {
                sx = x;
                s = i;
            }
            if(tx < x)
            {
                tx = x;
                t = i;
            }
        }
        sap_init();
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d %d %d", &u, &v, &c);
            addEdge(u, v, c);
            addEdge(v, u, c);
        }
        printf("%d\n", sap(s, t));
    }
    return 0;
}
