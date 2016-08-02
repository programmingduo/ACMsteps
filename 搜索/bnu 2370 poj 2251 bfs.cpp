#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;

char maze[35][35][35], vis[35][35][35];
int a, b, c, ans, flag;
int x[] = {0, 1, 0, -1, 0, 0};
int y[] = {1, 0, -1, 0, 0 ,0};
int z[] = {0, 0, 0, 0, 1, -1};

struct pos
{
    int x, y, z, dis;
}position[30000];

int in(int i, int j, int k)
{
    if(i >= 0 && j >= 0 && k >= 0 && i < a && j < b && k < c)
        return 1;
    return 0;

}

void bfs(int i, int j, int k)
{
    flag = 0;
    pos temp, temp0;
    temp.x = i;
    temp.y = j;
    temp.z = k;
    temp.dis = 0;
    queue<pos> searched;
    searched.push(temp);
    int tempx, tempy, tempz, tempd;
    while(!searched.empty())
    {
        temp = searched.front();
        searched.pop();
        tempx = temp.x;
        tempy = temp.y;
        tempz = temp.z;
        tempd = temp.dis;

        for(int ii = 0; ii < 6; ii ++)
        {
            if(in(tempx + x[ii], tempy + y[ii], tempz + z[ii])
               && vis[tempx + x[ii]][tempy + y[ii]][tempz + z[ii]] == 0)
            {
                if(maze[tempx + x[ii]][tempy + y[ii]][tempz + z[ii]] == 'E')
                {
                    ans = tempd + 1;
                    flag = 1;
                    break;
                }
                temp0.x = tempx + x[ii];
                temp0.y = tempy + y[ii];
                temp0.z = tempz + z[ii];
                temp0.dis = tempd + 1;
                searched.push(temp0);
                vis[tempx + x[ii]][tempy + y[ii]][tempz + z[ii]] = 1;
            }
        }
        if(flag)
            break;
    }
}

int main ()
{
    while(~scanf("%d%d%d", &a, &b, &c))
    {
        if(a == 0 && b == 0 && c == 0)
            break;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < a; i ++)
        {
            for(int j = 0; j < b; j ++)
            {
                scanf("%s", maze[i][j]);
                for(int k = 0; k < c; k ++)
                {
                    if(maze[i][j][k] == '#')
                        vis[i][j][k] = 1;
                }
            }
        }
        for(int i = 0; i < a; i ++)
        {
            for(int j = 0; j < b; j ++)
                for(int k = 0; k < c; k ++)
            {
                if(maze[i][j][k] == 'S')
                    bfs(i, j, k);
            }
        }
        if(flag)
            printf("Escaped in %d minute(s).\n", ans);
        else
            printf("Trapped!\n");
    }
}
