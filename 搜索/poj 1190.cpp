#include<cstdio>
#include<cmath>

const int INF = 0x3fffffff;

int n, m, best;

int min(int a, int b)
{
    return a< b? a: b;
}

int mins[24], minv[25];
void init()
{
    mins[0] = minv[0] = 0;
    for(int i = 1; i < 22; i ++)
    {
        mins[i] = i * i * 2+ mins[i - 1];
        minv[i] = i * i * i + minv[i - 1];
    }
}

void dfs(int dep, int r, int h, int v, int s)
{
    if(dep == 0)
    {
        if(v == 0 && s < best)
            best = s;
        return ;
    }

    if(s + mins[dep] > best || v < minv[dep] || 2 )
        return ;

    for(int i = min(r - 1, sqrt(v)); i >= dep; i --)
    {
        if(dep == m)
        s = i * i;
        for(int j = min(h - 1, v / (i * i)); j >= dep; j --)
        {
            dfs(dep - 1, i, j, v - i * i * j, s + 2 * i * j);
        }
    }
}

int main ()
{
    init();
    while(~scanf("%d %d", &n, &m))
    {
        best = INF;
        dfs(m, sqrt(n) + 1, n + 1, n, 0);
        if(best == INF)
            printf("0\n");
        else
            printf("%d\n", best);
    }
}
