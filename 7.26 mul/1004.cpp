#include<cstdio>
#include<vector>
#include<string.h>

using namespace std;

vector<int> v;
int n, m, a[100][100], num[40][40], maxt, flag;
int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};

int in(int i, int j)
{
    if(i < 1 || i > n || j < 1 || j > m)
        return 0;
    return 1;
}

void flap(int i, int j)
{
    a[i][j] = (a[i][j] + 2) % 3;
    for(int k = 0; k < 4; k ++)
    {
        int x = i + xx[k];
        int y = j + yy[k];
        if(in(x, y))
            a[x][y] = (a[x][y] + 1) % 3;
    }
}

void dfs(int step, int thisi, int thisj)
{
    if(flag || step > maxt)
        return ;
    flag = 1;
    for(int i = 1; i <= n && flag; i ++)
    {
        for(int j = 1; j <= m && flag; j ++)
        {
            if(a[i][j])
            {
                flag = 0;
            }
        }
    }
    if(flag)
    {
        maxt = step;
        v.clear();
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                if(num[i][j])
                {
                    v.push_back(num[i][j]);
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return ;
    }

    for(int i = thisi; i <= thisi; i ++)
    {
        for(int j = thisj + 1; j <= m; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                num[i][j] = k;
                if(k)
                {
                    flap(i, j);
                }
                dfs(step+k, i, j);
                if(flag)
                    return ;
            }
            num[i][j] = 0;
            flap[i][j];
        }
    }

    for(int i = thisi + 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            for(int k = 0; k < 3; k ++)
            {
                num[i][j] = k;
                if(k)
                {
                    flap(i, j);
                }
                dfs(step+k, i, j);
                if(flag)
                    return ;
            }
            num[i][j] = 0;
            flap[i][j];
        }
    }
}

void print()
{
    int total = v.size();
    printf("%d\n", maxt - 1);
    for(int i = 0; i < total; i ++)
    {
        int t = v[i ++];
        int x = v[i ++];
        int y = v[i];
        for(int j = 0; j < t; j ++)
        {
            printf("%d %d\n", x, y);
        }
    }
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        memset(num, 0, sizeof(num));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        flag = 0;
        for(maxt = 0; maxt < 2*n*m && !flag; maxt ++)
        {
            for(int i = 0; i < 3 && !flag; i ++)
            {
                num[1][1] = i;
                if(i)
                    flap(1, 1);
                dfs(i, 1, 1);

            }
            num[1][1] = 0;
        }

        print();
    }
    return 0;
}
