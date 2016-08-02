#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;

const int num = 505;
long long graph[num][num], vis[num], dis[num], cnt[num];
//采用邻接矩阵存储图，一定注意图是单向的还是双向的
int N;

void spfa_init()
{
    for(int i = 0; i <= N; i ++)
        for(int j = 0; j <= N; j ++)
        graph[i][j] = 100000000;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i <= N; i ++)
        dis[i] = 100000000;
}

bool spfa(int a)
{
    dis[a] = 0;
    queue<int> q;
    q.push(a);
    cnt[a] ++;
    vis[a] = 1;
    while(!q.empty())
    {
        a = q.front();
        vis[a] = 0;
        q.pop();
        for(int i = 1; i <= N; i ++)
        {
            if(graph[a][i] != 100000000)
            {
                if(dis[i] > dis[a] + graph[a][i])
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                    dis[i] = dis[a] + graph[a][i];
                    cnt[i] ++;
                    if(cnt[i] > N)
                        return true;
                }
            }
        }
    }
    return false;
}


int main ()
{
    int T, W, M, a, b, c;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d%d", &N, &M, &W);
        spfa_init();
        for(int i = 0; i < M; i ++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(graph[a][b] > c)
                graph[a][b] = graph[b][a] = c;
        }
        for(int i = 0; i < W; i ++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(graph[a][b] > -1 * c)
                graph[a][b] = -1 * c;
        }
        bool flag = spfa(a);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
