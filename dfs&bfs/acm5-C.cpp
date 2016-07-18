#include<cstdio>
#include<string.h>

int num[20][20], flag, a, b, c;
char operat[20][20];
double now;

int x[] = {0, 2, 0, -2};
int y[] = {2, 0, -2, 0};

int in(int m, int n)
{
    if(m >= 0 && m < a && n >= 0 && n < b)
        return 1;
    return 0;
}

void dfs(int m, int n)
{
    if(now == c)
    {
        flag = 1;
        return ;
    }
    int tempx, tempy;
    for(int i = 0; i < 4; i ++)
    {
        tempx = m + x[i];
        tempy = n + y[i];
        if(!in(tempx, tempy))
            continue;
        if(!num[(m+tempx)/2][(n+tempy)/2])
            continue;
        num[(m+tempx)/2][(n+tempy)/2] = 0;
        switch(operat[(m+tempx)/2][(n+tempy)/2])
        {
        case '*':
            now = now * num[tempx][tempy];
            break;
        case '+':
            now = now + num[tempx][tempy];
            break;
        case '/':
            now = now / num[tempx][tempy];
            break;
        case '-':
            now = now - num[tempx][tempy];
            break;
        }
        dfs(tempx, tempy);
        num[(m+tempx)/2][(n+tempy)/2] = 1;
    }
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d%d", &a, &b, &c);
        memset(num, 1, sizeof(num));
        for(int i = 0; i < a; i ++)
        {
            for(int j = 0; j < b; j ++)
            {
                if(i % 2 == 0 && j % 2 == 0)
                    scanf("%d", &num[i][j]);
                else
                    scanf("%c", &operat[i][j]);
            }
        }
        flag = 0;
        for(int i = 0; i < a; i += 2)
            for(int j = 0; j < b; j += 2)
            {
                now = num[i][j];
                dfs(i, j);
            }
        if(flag)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}
