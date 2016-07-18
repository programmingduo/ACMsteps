#include<cstdio>
#include<queue>
#include<string.h>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int in[505], m[505][505], ans[505];
int main ()
{
    int n, k, a, b;
    while(~scanf("%d %d", &n, &k))
    {
        memset(in, 0, sizeof(in));
        memset(m, 0, sizeof(m));
        while(k --)
        {
            scanf("%d %d", &a, &b);
            if(m[a][b] == 0)
                in[b] ++;
            m[a][b] = 1;
        }
        for(int i = 1; i <= n; i ++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        int temp, total = 0;
        while(!q.empty())
        {
            temp = ans[total ++] = q.top();
            q.pop();
            for(int i = 1; i <= n; i ++)
            {
                if(m[temp][i])
                {
                    in[i] --;
                    if(in[i] == 0)
                        q.push(i);
                }
            }
        }

        for(int i = 0; i < total; i ++)
        {
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
