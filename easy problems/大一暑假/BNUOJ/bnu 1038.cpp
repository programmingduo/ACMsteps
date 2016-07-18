#include<cstdio>

int c, r, hang[] = {0, -1, 0, 1}, lie[] = {-1, 0, 1, 0}, ans = 0;
char map[110][110];

void dfs(int h, int l)
{
    if(h < 0 || h >= r || l < 0 || l >= c || map[h][l] == '*')
        return ;
    map[h][l] = '*';
    for(int i = 0; i < 4; i ++)
        dfs(h + hang[i], lie[i] + l);
}

void init()
{
    ans = 0;
    for(int i = 0; i < c; i ++)
    {
        dfs(0, i);
        dfs(r - 1, i);
    }
    for(int i = 0; i < r; i ++)
    {
        dfs(i, 0);
        dfs(i, c - 1);
    }
    for(int i = 0; i < r; i ++)
    {
        for(int j = 0; j < c; j ++)
        {
            if(map[i][j] == '.')
                ans ++;
        }
    }
}

int main ()
{
    while(~scanf("%d%d", &r, &c))
    {
        for(int i = 0; i < r; i ++)
        {
            scanf("%s", map[i]);
        }
        init();
        printf("%d\n", ans);
    }
    return 0;
}
