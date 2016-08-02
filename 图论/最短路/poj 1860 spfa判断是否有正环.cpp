#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;

int e;
int head[10500], vis[10005], cnt[10050];
double dis[10050];
//dis可能是小数

struct node
{
    int v, next;
    double r, c;
}edge[1500];

//采用邻接表的方式存储图
void add(int a, int b, double r, double c)
{
    edge[e].v = b;
    edge[e].r = r;
    edge[e].c = c;
    edge[e].next = head[a];
    head[a] = e ++;
}

void SPFA_init()
{
    e = 0;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    memset(head, -1, sizeof(head));
}

int SPFA(int source, double much, int N)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    dis[source] = much;
    cnt[source] ++;
    while(!q.empty())
    {
        int first = q.front();
        q.pop();
        vis[first] = 0;
        for(int i = head[first]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            double tempdis = (dis[first] - edge[i].c) * edge[i].r;
            if(dis[v] < tempdis)
            {
                dis[v] = tempdis;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
                cnt[v] ++;
                if(cnt[v] > N + 1)
                    return -1;
            }
        }
    }
    return 1;
}

int main ()
{
    int N, M, a, b, source;
    double much, rab, rba, cba, cab;
    scanf("%d%d%d%lf", &N, &M, &source, &much);
    SPFA_init();
    for(int i = 0; i < M; i ++)
    {
        scanf("%d%d%lf%lf%lf%lf", &a, &b, &rab, &cab, &rba, &cba);
        add(a, b, rab, cab);
        add(b, a, rba, cba);
    }
    int ans = SPFA(source, much, N);
    if(ans == -1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
