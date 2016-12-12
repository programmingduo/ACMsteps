#include<cstdio>
#include<string.h>
#include<queue>
#include<cmath>
using namespace std;

const int maxNode = 210;
const int INF = 0x3fffffff;

bool inq[maxNode];
char org[105][105];
int  pre[maxNode], res[maxNode][maxNode], cost[maxNode][maxNode], d[maxNode];

struct node
{
    int x, y;
}h[maxNode], m[maxNode];

bool SPFA(int s, int t)
{
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    memset(pre, -1, sizeof(pre));
    inq[s] = 1;
    q.push(s);
    for(int i = s; i <= t; i ++)
        d[i] = INF;
    d[s] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int i = s; i <= t; i ++)
        {
            if(res[u][i] && d[u] + cost[u][i] < d[i])
            {
                d[i] = d[u] + cost[u][i];
                pre[i] = u;
                if(!inq[i])
                {
                    inq[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    if(pre[t] == -1)
        return false;
    return true;
}

int MCMF(int s, int t)
{
    int mincost = 0;
    while(SPFA(s, t))
    {
        int v = t;
        while(v != -1)
        {
            res[pre[v]][v] -= 1;
            res[v][pre[v]] += 1;
            v = pre[v];

        }
        mincost += d[t];
    }
    return mincost;
}

int main ()
{
    int r, c;
    while(~scanf("%d %d", &r, &c) && r && c)
    {
        for(int i = 1; i <= r; i ++)
        {
            scanf("%s", org[i]+1);
        }

        int house = 0, man = 0;
        for(int i = 1; i <= r; i ++)
        {
            for(int j = 1; j <= c; j ++)
            {
                if(org[i][j] == 'H')
                {
                    h[house].x = i;
                    h[house].y = j;
                    house ++;
                }
                if(org[i][j] == 'm')
                {
                    m[man].x = i;
                    m[man].y = j;
                    man ++;
                }
            }
        }
        memset(res, 0, sizeof(res));
        memset(cost, 0, sizeof(cost));
        int s = 0, t = house + man + 1;
        for(int i = 1; i <= house; i ++)
            res[s][i] = 1;

        for(int i = 0; i < house; i ++)
        {
            for(int j = 0; j < man; j ++)
            {
                int dis = abs(h[i].x - m[j].x) + abs(h[i].y - m[j].y);
                res[i + 1][j + house + 1] = 1;
                cost[i + 1][j + house + 1] = dis;
                cost[j + house + 1][i + 1] = -dis;
            }
        }

        for(int i = house + 1; i < t; i ++)
            res[i][t] = 1;
        printf("%d\n", MCMF(s, t));
    }
    return 0;
}
