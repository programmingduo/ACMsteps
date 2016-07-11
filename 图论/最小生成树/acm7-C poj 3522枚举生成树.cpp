#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

struct node
{
    int a, b, w;
}e[100000];

int cmp(node x, node y)
{
    return x.w < y.w;
}

int main ()
{
    int vertex, edge, big, little, flag, ans, total, tempa, tempb;
    int vis[105];
    while(~scanf("%d%d", &vertex, &edge))
    {
        if(vertex == 0 && edge == 0)
            break;
        for(int i = 0; i < edge; i ++)
        {
            scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
        }
        sort(e, e + edge, cmp);
        ans = -1;
        for(int i = 0; i < edge; i ++)
        {
            little = e[i].w;
            memset(vis, 0, sizeof(vis));
            vis[e[i].a] = 1;
            vis[e[i].b] = 1;
            total = 1;
            if(vertex == 2)
            {
                ans = 0;
                break;
            }
            for(int j = i + 1; j < edge; j ++)
            {
                flag = 0;
                if(total == vertex - 1)
                    break;
                tempa = e[j].a;
                tempb = e[j].b;
                if(!vis[tempa] || !vis[tempb])
                {
                    big = e[j].w;
                    vis[tempa] = 1;
                    total ++;
                }
            }
            if(total < vertex - 1)
                break;
            else if(ans == -1)
                ans = big - little;
            else
                ans = min(ans, big - little);
        }
        printf("%d\n", ans);
    }
    return 0;
}
