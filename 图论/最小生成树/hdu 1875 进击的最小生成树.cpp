#include<cstdio>
#include<algorithm>

struct node
{
    int a, b, c;
}edge[100000];

int cmp(node x, node y)
{
    return x.c < y.c;
}

int f[10000];

int find(int i)
{
    if(f[i] == i)
        return i;
    else
        return f[i] = find(f[i]);
}

int main ()
{
    int N;
    while(~scanf("%d", &N) && N)
    {
        for(int i = 0; i <= N; i ++)
            f[i] = i;
        int total = 0, ans = 0;
        int a, b, c, d;
        int temp = N * (N - 1) / 2;
        for(int i = 0; i < temp; i ++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if(d)
            {
                int x = find(a), y = find(b);
                if(x != y)
                    f[x] = y;
            }
            else
            {
                edge[total].a = a;
                edge[total].b = b;
                edge[total].c = c;
                total ++;
            }
        }
        std::sort(edge, edge + total, cmp);
        for(int i = 0; i < total; i ++)
        {
            int x = find(edge[i].a), y = find(edge[i].b);
            if(x != y)
            {
                f[x] = y;
                ans += edge[i].c;
            }
        }
        printf("%d\n", ans);
    }
}
