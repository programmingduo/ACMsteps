#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

struct edge
{
    int x, y, w;
    edge(int a = 0, int b = 0, int c = 0) : x(a), y(b), w(c) {}
}e[40010];

bool comp(const edge &a, const edge &b)
{
    return a.w < b.w;
}

struct point
{
    int x, y;
} p[220];

int n, m, ans, fa[220];

int getfather(int a)
{
    if(a == fa[a])
        return a;
    else
        return fa[a] = getfather(fa[a]);
}

void kruskal()
{
    sort(e, e + m, comp);
    for(int i = 0; i < n; i ++)
        fa[i] = i;
    for(int i = 0; i < m; i ++)
    {
        int t1 = getfather(e[i].x);
        int t2 = getfather(e[i].y);
        if(t1 != t2)
        {
            fa[t1] = t2;
            if(getfather(0) == getfather(1))
            {
                ans = e[i].w;
                break;
            }
        }
    }
}

int main ()
{
    int cnt = 1;
    while(~scanf("%d", &n) && n)
    {
        m = ans = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
        }

        for(int i = 0; i < n; i ++)
        {
            for(int j = i + 1; j < n; j ++)
            {
                e[m].x = i;
                e[m].y = j;
                e[m].w=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
                m ++;
            }
        }
        kruskal();
        printf("Scenario #%d\n", cnt ++);
        printf("Frog Distance = %.3lf\n\n", sqrt((double) ans));
    }
    return 0;
}
