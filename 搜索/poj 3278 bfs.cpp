#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;

struct node
{
    int num, len;
};
int vis[100005];

int main ()
{
    int N, K;
    while(~scanf("%d%d", &N, &K))
    {
        memset(vis, 0, sizeof(vis));
        node pos;
        int ans;
        pos.num = N;
        pos.len = 0;
        queue<node> q;
        while(!q.empty())
            q.pop();
        q.push(pos);
        vis[N] = 1;
        while(!q.empty())
        {
            pos = q.front();
            q.pop();
            int n = pos.num, time = pos.len;
            if(n == K)
            {
                ans = time;
                break;
            }
            if(n + 1 <= 100000 && !vis[n + 1])
            {
                vis[n + 1] = 1;
                pos.num = n + 1;
                pos.len = time + 1;
                q.push(pos);
            }
            if(n - 1 >= 0 && !vis[n - 1])
            {
                vis[n - 1] = 1;
                pos.num = n - 1;
                pos.len = time + 1;
                q.push(pos);
            }
            if(n * 2 <= 100000 && !vis[n * 2])
            {
                vis[n * 2] = 1;
                pos.num = n * 2;
                pos.len = time + 1;
                q.push(pos);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
