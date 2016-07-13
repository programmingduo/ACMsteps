#include<cstdio>
#include<string.h>

//记录一下机器人的方向就行了
//因为题目中的xy坐标轴互换了，所以在使用过程中要 转换一下。
//如果改变方向的话就不走了

struct node{
    int r, c;
    char d;
}robot[106];

int graph[106][105];
int direx[4] = {0, 1, 0, -1};
int direy[4] = {-1, 0, 1, 0};

int main ()
{
    int T, x, y, n, m, num, repeat, crash, crash1, crash2;
    char f;
    scanf("%d", &T);
    while(T --)
    {
        int flag = 0;
        memset(graph, 0, sizeof(graph));
        scanf("%d%d", &y, &x);
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d%d%c%c", &robot[i].c, &robot[i].r, &robot[i].d, &robot[i].d);
            graph[robot[i].r][robot[i].c] = 1;
        }
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%c%c%d", &num, &f, &f, &repeat);
            if(flag)
                continue;
            int temp = 0;
            switch(robot[num].d)
            {
            case 'W':
                temp = 0;
                break;
            case 'N':
                temp = 1;
                break;
            case 'E':
                temp = 2;
                break;
            case 'S':
                temp = 3;
                break;
            }
            if(f == 'L')
            {
                temp = (temp + 400 - repeat) % 4;
                switch(temp)
                {
                case 0:
                    robot[num].d = 'W';
                    break;
                case 1:
                    robot[num].d = 'N';
                    break;
                case 2:
                    robot[num].d = 'E';
                    break;
                case 3:
                    robot[num].d = 'S';
                    break;
                }
                continue;
            }
            else if(f == 'R')
            {
                temp = (temp + repeat) % 4;
                switch(temp)
                {
                case 0:
                    robot[num].d = 'W';
                    break;
                case 1:
                    robot[num].d = 'N';
                    break;
                case 2:
                    robot[num].d = 'E';
                    break;
                case 3:
                    robot[num].d = 'S';
                    break;
                }
                continue;
            }
            int tx = robot[num].r;
            int ty = robot[num].c;
            graph[tx][ty] = 0;
            for(int j = 1; j <= repeat; j ++)
            {
                tx += direx[temp];
                ty += direy[temp];
                if(tx < 1 || tx > x || ty < 1 || ty > y)
                {
                    flag = 1;
                    crash = num;
                    break;
                }
                if(graph[tx][ty] == 1)
                {
                    flag = 2;
                    crash1 = num;
                    for(int k = 1; k <= n; k ++)
                    {
                        if(robot[k].r == tx && robot[k].c == ty)
                        {
                            crash2 = k;
                            break;
                        }
                    }
                    break;
                }
            }
            robot[num].r = tx;
            robot[num].c = ty;
            graph[tx][ty] = 1;
        }
        if(flag == 1)
            printf("Robot %d crashes into the wall\n", crash);
        else if(flag == 2)
            printf("Robot %d crashes into robot %d\n", crash1, crash2);
        else
            printf("OK\n");
    }
    return 0;
}
