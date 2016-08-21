#include<cstdio>
#include<queue>
#include<string.h>

using namespace std;

const int maxn = 3000004;

int in[maxn], ans[maxn], next[maxn], head[maxn], sum;
int to[maxn];
priority_queue<int> q;

void add(int a, int b)
{
    next[sum] = head[a];
    to[sum] = b;
    head[a] = sum ++;
}

int main()
{
    int n, m, a, b;
    while(~scanf("%d %d", &n, &m))
    {
        while(!q.empty())
            q.pop();
        memset(in, 0, sizeof(in));
        memset(head, -1, sizeof(head));
        sum = 0;
        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d", &b, &a);
            add(a, b);
            in[b] ++;
        }
        for(int i = 1; i <= n; i ++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        int total = 0;
        while(!q.empty())
        {
            int v = q.top();
            ans[total ++] = v;
            q.pop();
            for(int i = head[v]; i != -1; i = next[i])
            {
                int u = to[i];
                in[u] --;
                if(in[u] == 0)
                {
                    q.push(u);
                }
            }
        }
        int flag = 0;
        for(int i = n - 1; i >= 0; i --)
        {
            if(flag)
                printf(" ");
            flag = 1;
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
