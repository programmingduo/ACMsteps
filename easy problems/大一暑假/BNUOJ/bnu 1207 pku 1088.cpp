#include<cstdio>
#include<cstring>
#include<algorithm>

int hight[105][105], dp[105][105];
int row, column;
int r[] = {-1, 0, 1, 0}, c[] = {0, -1, 0, 1};

void dpsearch(int hang, int lie)
{
    if(hang == 0 || lie == 0 || hang > row || lie > column)
        return ;
    for(int i = 0; i < 4; i ++)
    {
        int hang2 = hang + r[i], lie2 = lie + c[i];
        if(hight[hang][lie] < hight[hang2][lie2] && dp[hang][lie] + 1 > dp[hang2][lie2])
        {
            dp[hang2][lie2] = dp[hang][lie] + 1;
            dpsearch(hang2, lie2);
        }
    }
}

int main ()
{
    memset(dp, 0, sizeof(dp));
    scanf("%d%d", &row, &column);
    for(int i = 1; i <= row; i ++)
    {
        for(int j = 1; j <= column; j ++)
        {
            scanf("%d", &hight[i][j]);
        }
    }

    for(int i = 1; i <= row; i ++)
    {
        for(int j = 1; j <= column; j ++)
        {
            dpsearch(i, j);
        }
    }

    int maxn = 0;
    for(int i = 1; i <= row; i ++)
    {
        for(int j = 1; j <= column; j ++)
        {
            maxn = std::max(maxn, dp[i][j]);
        }
    }
    printf("%d\n", maxn + 1);

    return 0;
}
