#include<cstdio>
#include<string.h>

int x[] = {0, -1, 0, 1};
int y[] = {1, 0, -1, 0};
int ans, r, c;
int vis[50][50];
char graph[25][25];

int in(int i, int j)
{
    if(i >= 0 && i < r && j >= 0 && j < c)
        return 1;
    return 0;
}

void dfs(int i, int j)
{
    vis[i][j] = 1;
    ans ++;
    for(int k = 0; k < 4; k ++)
    {
        int tempx = i + x[k];
        int tempy = j + y[k];
        if(!in(tempx, tempy))
            continue;
        else
        {
            if(!vis[tempx][tempy] && graph[tempx][tempy] == '.')
                dfs(tempx, tempy);
        }

    }
}

int main ()
{
    while(~scanf("%d%d", &c, &r))
    {
        memset(vis, 0, sizeof(vis));
        if(r == 0 && c == 0)
            break;
        for(int i = 0; i < r; i ++)
        {
            scanf("%s", graph[i]);
        }
//        for(int i = 0; i < r; i ++)
//        {
//            for(int j = 0; j < c; j ++)
//                printf("%c ", graph[i][j]);
//            printf("\n");
//        }
        ans = 0;
        for(int i = 0; i < r; i ++)
        {
            for(int j = 0; j < c; j ++)
            {
                if(graph[i][j] == '@')
                {
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
}
