#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, x[] = {-1, 0, 0, 1}, y[] = {0, -1, 1, 0};
char square[2][11][11];

struct node
{
    int x, y, z;
    int step;
};

bool isok(node& n)
{
    if(n.x < 0 || n.x >= N || n.y < 0 || n.y >= M)
        return false;
    if(square[n.z][n.x][n.y] == '*')
        return 0;
    if(square[n.z][n.x][n.y] == '#')
    {
        if(square[1 ^ n.z][n.x][n.y] == '#' || square[1 ^ n.z][n.x][n.y] == '*')
        {
            square[n.z][n.x][n.y] = '*';
            return 0;
        }
        n.z = 1 ^ n.z;
    }
    return 1;
}

int main ()
{
    int cases, visit[2][11][11];
    scanf("%d", &cases);
    queue<node> m;
    while(cases --)
    {
        while(!m.empty())  m.pop();
        memset(square, 0, sizeof(square));
        memset(visit, -1, sizeof(visit));
        int T, flag = 0;
        scanf("%d%d%d", &N, &M, &T);
        for(int k = 0; k < 2; k ++)
        for(int i = 0; i < N; i ++)
        scanf("%s", square[k][i]);

        node temp, ttemp;
        temp.x = 0;
        temp.y = 0;
        temp.z = 0;
        temp.step = 0;
        m.push(temp);
        visit[0][0][0] = 1;
        while(!m.empty())
        {
            temp = m.front();
            m.pop();
            for(int i = 0; i < 4; i ++)
            {
                ttemp.x = temp.x + x[i];
                ttemp.y = temp.y + y[i];
                ttemp.z = temp.z;
                if(isok(ttemp) && visit[ttemp.z][ttemp.x][ttemp.y] == -1)
                {
                    visit[ttemp.z][ttemp.x][ttemp.y] = 0;
                    if(square[ttemp.z][ttemp.x][ttemp.y] == 'P' && temp.step + 1 <= T)
                    {
                        flag = 1;
                        break;
                    }
                    ttemp.step = temp.step + 1;
                    m.push(ttemp);
                }
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
