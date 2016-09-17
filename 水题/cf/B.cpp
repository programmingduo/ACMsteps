#include<cstdio>


int x, y, n;
long long c[505][505], sum, temp;

int main ()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j  <= n; j ++)
        {
            scanf("%I64d", &c[i][j]);
            if(c[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }

    sum = 0;
    if(n == 1)
    {
        printf("1\n");
    }
    else
    {
        if(x == 1)
        {
            for(int i = 1; i <= n; i ++)
            {
                sum += c[2][i];
            }
        }
        else
        {
            for(int i = 1; i <= n; i ++)
            {
                sum += c[1][i];
            }
        }

        temp = sum;
        for(int i = 1; i <= n; i ++)
        {
            sum -= c[x][i];
        }
        c[x][y] = sum;
        sum = temp;

        int flag = 1;
        for(int i = 1; i <= n && flag; i ++)
        {
            temp  =0;
            for(int j = 1; j <= n; j ++)
            {
                temp += c[i][j];
            }
            if(temp != sum)
                flag = 0;
        }

        for(int i = 1; i <= n && flag; i ++)
        {
            temp  =0;
            for(int j = 1; j <= n; j ++)
            {
                temp += c[j][i];
            }
            if(temp != sum)
                flag = 0;
        }

        temp = 0;
        for(int i = 1; i <= n && flag; i ++)
            temp += c[i][i];
        if(temp != sum)
            flag = 0;

        temp = 0;
        for(int i = 1; i <= n && flag; i ++)
            temp += c[i][n + 1 - i];
        if(temp != sum)
            flag = 0;

        if(flag && c[x][y] > 0)
        {
            printf("%I64d\n", c[x][y]);
        }
        else
            printf("-1\n");
    }
}

