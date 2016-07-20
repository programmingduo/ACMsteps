#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int fa[100005], in[100005];
vector<int> v[100006];

struct node
{
    int w;
    int x, y;
}edge[1000006];

int cmp(node a, node b)
{
    return a.w<b.w;
}

int find(int x)
{
    return fa[x] == x? x: fa[x]=find(fa[x]);
}

int main ()
{
    int T, n, m,a, b,w;
    scanf("%d", &T);
    while(T --)
    {
        int total = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d %d", &a, &b, &w);
            edge[total].x = a;
            edge[total].y = b;
            edge[total].w = w;
            total ++;
        }

        for(int i = 1; i <= n; i ++)
            fa[i] = i;
        for(int i = 1; i <= n; i ++)
            v[i].clear();
        memset(in, 0, sizeof(in));
        while(!q.empty)
            q.pop();
        long long all = 0, ans = 0;

        sort(edge, edge + total, cmp);
        for(int i = 0; i < total && all < n; i ++)
        {
            a = find(edge[i].x);
            b = find(edge[i].y);
            if(a != b)
            {
                all ++;
                in[edge[i].x] ++;
                v[edge[i].x].push_back(edge[i].y);
                v[edge[i].x].push_back(edge[i].w);
                in[edge[i].y] ++;
                v[edge[i].y].push_back(edge[i].x);
                v[edge[i].y].push_back(edge[i].w);
                ans += edge[i].w;
                fa[b] = a;
            }
        }

        for(int i = 1; i <= n; i ++)
        {
            if(in[i] == 1)
            {
                sum[i] = 1;
                q.push(i);
                q.push(v[i][1]);
            }
        }
        while(!q.empty)
        {
            int t = q.top();
            q.pop();
            w = q.top();
            q.pop();
            int len = v[t].size();
            for(int i = 0; i < len; i += 2)
            {
                int temp = v[t][i];
                in[temp] --;
                sum[temp] += sum[t];
                if(in[temp] == 0)
                {
                    q.push(i);
                    q.push(i + 1);
                }
            }

        }

        printf("%lld \n", ans);
    }
    return 0;
}
