#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;

int m, n;
int dis[500][500];
char prision[500][500];
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

int in(int i, int j)
{
    if(i < 0 || i >= m || j < 0 || j >= n)
        return 1;
    return 0;
}

void bfs(int a, int b)
{
    dis[a][b] = 0;
    queue<int> searchx, searchy;
    searchx.push(a);
    searchy.push(b);
    int tempx, tempy, temp1, temp2, tempd;
    while(!searchx.empty())
    {
        tempx = searchx.front();
        tempy = searchy.front();
        searchx.pop();
        searchy.pop();
        for(int i = 0; i < 4; i ++)
        {
            temp1 = tempx + x[i];
            temp2 = tempy + y[i];
            if(in(temp1, temp2))
                continue;
            if(prision[temp1][temp2] == '#')
                continue;
            if(prision[temp1][temp2] == 'a')
                continue;
            if(prision[temp1][temp2] == 'x')
                tempd = dis[tempx][tempy] + 2;
            else
                tempd = dis[tempx][tempy] + 1;
            if(tempd < dis[temp1][temp2])
            {
                dis[temp1][temp2] = tempd;
                searchx.push(temp1);
                searchy.push(temp2);
            }
        }
    }
}

int main ()
{
    int ans;
    while(~scanf("%d%d", &m, &n))
    {
        for(int i = 0; i < m; i ++)
            scanf("%s", prision[i]);
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
            dis[i][j] = 10000000;
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(prision[i][j] == 'a')
                    bfs(i, j);
            }
        }
        ans = 10000000;
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(prision[i][j] == 'r')
                    ans = dis[i][j];
            }
        }
        if(ans < 10000000)
            printf("%d\n", ans);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}
