#include<cstdio>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

int a[1005][1005], is[1005], in[1005], out[1005];
struct node
{
    int num, po;
}b[1005];
int cmp(node x1, node x2)
{
    return x1.po > x2.po;
}
queue<int> q;

int main ()
{
    int n, m;
    while(~scanf("%d %d", &n, &m) && (m || n))
    {
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n; j ++)
            {
                scanf("%d", &a[i][j]);

            }
        }

        for(int i = 0; i < m; i ++)
        {
            scanf("%d", &b[i].num);
            is[b[i].num] = 1;
        }

        memset(in, 0, sizeof(in));
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(a[b[i].num][b[j].num])
                {
                    in[j] ++;
                    out[i] ++;
                }
            }
        }

        while(!q.empty())
            q.pop();
        for(int i = 0; i < m; i ++)
            if(in[i] == 0)
                q.push(i);

        int total = 0, flag = 0;
        while (!q.empty())
        {
            int t = q.front();
            b[t].po = total ++;
            t = b[t].num;
            q.pop();
            for(int i = 0; i < m; i ++)
            {
                if(a[t][b[i].num])
                {
                    in[i] --;
                    if(in[i] == 0)
                        q.push(i);
                }
            }
        }

        for(int i = 0; i < m; i ++)
        {
            if(in[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            printf("NO\n");
            continue;
        }

        std::sort(b, b + m, cmp);
        memset(in, 0, sizeof(in));
        for(int i = 1; i <= n; i ++)
        {
            if(is[i])
                continue;
            for(int j = 0; j < m; j ++)
            {
                if(a[b[j].num][i])
                    in[i] ++;
            }
        }
        for(int i = n; i > 0 && !flag; i --)
        {
            if(is[i])
                continue;

            for(int j = 0; j < m && in[i]; j ++)
            {
                if(a[b[j].num][i])
                    in[i] --;
                else
                    break;
            }
            if(in[i] == 0)
                flag = i;

        }
        printf("YES %d\n", flag);
    }
}
