#include<cstdio>

int n, m;

int topo_sort()
{
    for(int i = 0; i < m; i ++)
    {
        int u = a[i];
        if(innum[u] == 0)
        {

        }
    }
}

int main ()
{
    while(~scanf("%d %d", &n, &m) && (n != 0 || m != 0))
    {
        for(int i = 1; i <= n; i  ++)
        {
            for(int j = 1; j <= n; j ++)
            {
                scanf("%d", t);
                if(t)
                {
                    add_edge(i, j);
                }
            }
        }
        for(int i = 0; i < m; i ++)
            scanf("%d", &a[i]);
        int ans = 0;
        if(topo_sort())
            ans = add_p();
        if(ans)
            printf("YES %d\n", ans);
        else
            printf("NO\n");
    }
}
