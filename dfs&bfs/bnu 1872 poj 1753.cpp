#include<cstdio>
#include<string.h>

char graph[5][5];
int x[] = {0, 1, 0, -1, 0};
int y[] = {0, 0, 1, 0, -1};
int vis[5][5];
int ans, flag;

int in(int i, int j)
{
    if(i >= 0 && i < 4 && j >= 0 && j < 4)
        return 1;
    return 0;
}

void flip(int i, int j)
{
//    printf("%d %d\n", i, j);
    int tempx, tempy;
    for(int k = 0; k <= 4; k ++)
    {
        tempx = i + x[k];
        tempy = j + y[k];
        if(in(tempx, tempy))
        {
            if(graph[tempx][tempy] == 'b')
                graph[tempx][tempy] = 'w';
            else if(graph[tempx][tempy] == 'w')
                graph[tempx][tempy] = 'b';
        }
    }
//    for(int i = 0; i < 4; i ++)
//        {
//            for(int j  =0; j < 4; j ++)
//                printf("%c", graph[i][j]);
//            printf("\n");
//        }
}

void dfs(int step, int xx, int yy)
{
    if(step == ans)
    {
        int w = 0, b = 0;
        for(int i = 0; i < 4; i ++)
        {
            for(int j = 0; j < 4; j ++)
            {
                if(graph[i][j] != 'b')
                    w = 1;
                if(graph[i][j] != 'w')
                    b = 1;
            }
        }
        if(w && b)
            flag = 1;
        else
            flag = 0;
//        if(!flag)
//            for(int i = 0; i < 4; i ++)
//        {
//            for(int j  =0; j < 4; j ++)
//                printf("%c", graph[i][j]);
//            printf("\n");
//        }
        return ;
    }
    for(int j = yy, i = xx; j < 4 && flag; j ++)
    {
        if(vis[i][j])
            continue;
        flip(i, j);
        vis[i][j] = 1;
        dfs(step + 1, i, j);
        vis[i][j] = 0;
        flip(i, j);
    }
    for(int i = xx + 1; i < 4 && flag; i ++)
    {
        for(int j = 0; j < 4 && flag; j ++)
        {
            if(vis[i][j])
                continue;
            flip(i, j);
            vis[i][j] = 1;
            dfs(step + 1, i, j);
            vis[i][j] = 0;
            flip(i, j);
        }
    }
}

int main ()
{
    while(~scanf("%s", graph[0]))
    {
        memset(vis, 0, sizeof(vis));
        flag = 1;
        for(int i = 1; i < 4; i ++)
            scanf("%s", graph[i]);
        for(ans = 0; flag && ans < 17; ans ++)
        {
            dfs(0, 0, 0);
        }
        if(flag)
            printf("Impossible\n");
        else
            printf("%d\n", ans - 1);
    }
    return 0;
}
