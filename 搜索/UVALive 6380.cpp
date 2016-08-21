#include<cstdio>
#include<string.h>

int x[15], y[15], c[15];
int mm[55][55];
int n;

int min(int a, int b)
{
    return a<b ? a: b;
}

int get1(int a)
{
    int ans = 0;
    while(a)
    {
        ans += a %2;
        a /= 2;
    }
    return ans;
}

int xx[] = {0, 0, -1, 1};
int yy[] = {1, -1, 0, 0};

void set1(int a, int b, int cc)
{
    if(cc == 0)
        return ;
    if(mm[a][b] >= cc)
        return ;
    mm[a][b] = cc;
    for(int i = 0; i < 4; i ++)
    {
        if(a + xx[i] > 0 && a + xx[i] <= n && b + yy[i] > 0 && b + yy[i] <= n)
        {
            set1(a + xx[i], b + yy[i], cc - 1);
        }
    }
}

int main()
{
    int m;
    while(~scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d", &x[i], &y[i]);
        }
        for(int i = 0; i < m; i ++)
        {
            scanf("%d", &c[i]);
        }

        int ans = 100;
        for(int i = 0; i < (1 << m); i ++)
        {
            memset(mm, 0, sizeof(mm));

            for(int j = 0; j < m; j ++)
            {
                mm[x[j]][y[j]] = 1;
                if(i & (1 << j))
                {
                    if(c[j] == 0)
                        continue;
                    set1(x[j], y[j], c[j] + 1);
                }
            }
            int flag = 0;
            for(int j = 1; j <= n && !flag; j ++)
            {
                for(int k = 1; k <= n && !flag; k ++)
                {
                    if(!mm[j][k])
                        flag = 1;
                }
            }
            if(!flag)
                ans = min(ans, get1(i));
        }
        if(ans == 100)
            printf("-1\n");
        else
        printf("%d\n", ans);
    }
    return 0;
}
