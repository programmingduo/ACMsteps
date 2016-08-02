#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

char a[105][105];
typedef struct
{
    int x, y, dis;
}node;

int main ()
{
    int xx[] = {-1, 0, 1, 0}, yy[] = {0, -1, 0, 1};
    int x, y;
    queue<node> s;
    scanf("%d%d", &x, &y);
    for(int i = 0; i < x; i ++)
        scanf("%s", a[i]);
    for(int i = 0; i < x; i ++)
        for(int j = 0; j < y; j ++)
        if(a[i][j] == 'S')
    {
        node temp;
        temp.x = i;
        temp.y = j;
        temp.dis = 0;
        s.push(temp);
        goto asd;
    }
    asd:;

    node temp, temp1;
    int ans = 1 << 30;
    while(!s.empty())
    {
        temp = s.front();
        s.pop();
        for(int i = 0; i < 4; i ++)
        {
            int tempx = temp.x + xx[i], tempy = temp.y + yy[i];
            if(tempx < 0 || tempy < 0 || tempx >= x || tempy >= y)
                continue;
            if(a[tempx][tempy] == '.')
            {
                temp1.x = tempx;
                temp1.y = tempy;
                temp1.dis = temp.dis + 1;
                s.push(temp1);
                a[tempx][tempy] = '*';
            }
            else if(a[tempx][tempy] == '*')
                continue;
            else if(a[tempx][tempy] == 'T')
            {
                ans = temp.dis + 1;
                goto fdsa;
            }
        }
    }
    fdsa:;
    if(ans == 1 << 30)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}
