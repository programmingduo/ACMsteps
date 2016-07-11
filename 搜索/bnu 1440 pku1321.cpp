#include<cstdio>
#include<string.h>

int num[10], n, ans;
char map[10][10];

void dfs(int line, int k)
{
    if(k <= 0)
    {
        ans ++;
        return ;
    }
    if(line < 0)
        return ;
    for(int i = 0; i < n; i ++)
    {
        if(map[line][i] == '#' && num[i] == 0)
        {
            num[i] = 1;
            dfs(line - 1, k - 1);
            num[i] = 0;
        }
    }
    dfs(line - 1, k);
}

int main ()
{
    int k;
    while(~scanf("%d%d", &n, &k))
    {
        ans = 0;
        memset(num, 0, sizeof(num));
        if(n == -1 && k == -1)
            break;
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", map[i]);
        }
        dfs(n - 1, k);
        printf("%d\n", ans);
    }
    return 0;
}
