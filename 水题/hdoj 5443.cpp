#include<cstdio>

int a[100005];

int max(int x, int y)
{
    return x> y? x: y;
}

int dfs(int l, int r)
{
    if(l == r)
        return a[l];
    int mid = (l + r) >> 1;
    return max(dfs(l, mid), dfs(mid + 1, r));
}

int main ()
{
    int T,  n, l, r, q;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        scanf("%d", &q);
        while(q --)
        {
            scanf("%d %d", &l, &r);
            printf("%d\n", dfs(l, r));
        }
    }
    return 0;
}
