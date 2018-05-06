#include <cstdio>

int w, h;
char graph[50][50];
int leftx[] = {0, 1, 0, -1};
int lefty[] = {-1, 0, 1, 0};
int rightx[] = {0, 1, 0, -1};
int righty[] = {1, 0, -1, 0};

int in(int x, int y)
{
    if(x == 0 || y == 0 || x > h || y > w)
        return 0;
    return 1;
}

int leftDFS(int x, int y, int dir, int len)
{
    printf("%d %d %d\n", x, y, dir);
    if(graph[x][y] == 'E')
        return len;

    int tem = 1 - dir, xx, yy;
    for(int i = 0; i < 4; i ++)
    {
        tem = (tem + 1) % 4;
        xx = x + leftx[tem];
        yy = y + lefty[tem];
        if(in(xx, yy) && graph[xx][yy] == '.')
        {
            if(tem == 0)
                return leftDFS(xx, yy, 4, len + 1);
            else if(tem == 1)
                return leftDFS(xx, yy, 3, len + 1);
            else if(tem == 2)
                return leftDFS(xx, yy, 2, len + 1);
            else
                return leftDFS(xx, yy, 1, len + 1);
        }
    }
}

int rightDFS(int x, int y, int dir)
{

}

int BFS(int x, int y, int dir)
{

}

int main()
{
    int T, startx, starty, startdir, ans1, ans2, ans3;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &w, &h);
        for(int i = 1; i <= h; i ++)
        {
            for(int j =  1; j <= w; j ++)
            {
                scanf("%c", &graph[i][j]);
                printf("%c", graph[i][j]);
                if(graph[i][j] == 'S')
                {
                    startx = i;
                    starty = j;
                    if(i == 1)
                        startdir = 3;
                    else if(i == h)
                        startdir = 1;
                    else if(j == 1)
                        startdir = 2;
                    else
                        startdir = 4;
                }
            }
            getchar();
        }

        ans1 = leftDFS(startx, starty, startdir, 1);
//        ans2 = rightDFS(startx, starty, startdir, 1);
//        ans3 = BFS(startx, starty, 1);

        printf("%d %d %d\n", ans1, ans2, ans3);
    }

    return 0;
}
