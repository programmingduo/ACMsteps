#include<cstdio>

int ans = 0;
int dfs(int p, int q)
{
    if(p == 1 && q == 1)
        return 1;
    if(p <= 0 || q <= 0)
        return 0;
    int ret = 0;
    if(ret = dfs(p, q-p))
        return ret*2;
    else if(ret = dfs(p-q, q))
        return ret*2+1;
    return 0;
}

int main()
{
    int T, n, p, q;
    scanf("%d", &T);
    while(T --)
    {
        ans = 0;
        scanf("%d %d/%d", &n, &p, &q);
        ans = dfs(p, q);
        printf("%d %d\n", n, ans);

    }
}
