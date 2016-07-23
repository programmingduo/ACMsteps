#include<cstdio>

const int maxn = 10000000;
int fa[158], son[159], bro[158];
int dp[155][155];
int n, p;
int min(int x, int y)
{
    return x<y? x: y;
}

void dfs(int id)
{
    for(int i = 0; i <= p; i ++)
    {
        dp[id][i] = maxn;
    }
    dp[id][1] = 0;
    int k = son[id];
    while(k)
    {
        dfs(k);
        for(int i = p; i >= 1; i --)
        {
            int temp = dp[id][i] + 1;
            for(int j = 1; j < i; j ++)
            {
                temp = min(temp, dp[id][i-j] + dp[k][j]);
            }
            dp[id][i] = temp;
        }
        k = bro[k];
    }
    return ;
}

int main()
{
    scanf("%d %d", &n, &p);
    int x, y;
    for(int i = 1; i < n; i ++)
    {
        scanf("%d %d", &x, &y);
        bro[y] = son[x];
        son[x] = y;
        fa[y] = x;
        dp[i][1] = 0;
    }
    int root;
    for(int i = 1; i <= n; i ++)
        if(!fa[i])
        {
            root = i;
            break;
        }

    dfs(root);
    int ans = dp[root][p];
    for(int i = 1; i <= n; i ++)
    {
        if(i == root)
        continue;
        ans = min(ans, dp[i][p]+1);
    }
    printf("%d\n", ans);

    return 0;
}
