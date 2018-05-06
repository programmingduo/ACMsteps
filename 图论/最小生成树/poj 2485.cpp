#include <cstdio>
#include <algorithm>

struct node
{
    int l, r, w;
}edge[250005];

int fa[505];
int total;

bool cmp(node a, node b)
{
    return a.w < b.w;
}

int findfa(int a)
{
    return fa[a] == a? a: fa[a] = findfa(fa[a]);
}

int main()
{
    int T, N, w, l, r, fal, far, ans;
    scanf("%d", &T);
    while(T --)
    {
        total = 1;
        scanf("%d", &N);
        for(int i = 1; i <= N; i ++)
        {
            fa[i] = i;
        }

        for(int i = 1; i <= N; i ++)
        {
            for(int j = 1; j <= N; j ++)
            {
                scanf("%d", &w);
                if(j > i)
                {
                    edge[total].l = i;
                    edge[total].r = j;
                    edge[total].w = w;
                    total ++;
                }
            }
        }

        std::sort(edge, edge + total, cmp);

        for(int i = 0; i < total; i ++)
        {
            l = edge[i].l;
            r = edge[i].r;
            w = edge[i].w;

            fal = findfa(l);
            far = findfa(r);
            if(fal != far)
            {
                fa[far] = fal;
                ans = w;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
