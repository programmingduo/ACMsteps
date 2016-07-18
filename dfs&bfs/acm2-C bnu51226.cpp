#include<iostream>
#include<cstdio>

using namespace std;
int h, c, map[505][505],a, b, c0, d, t, ans, num[505][505], num0[505][505];
int main ()
{
    string temp;
    while(~scanf("%d%d", &h, &c))
    {
        for(int i = 0; i < h; i ++)
        {
            cin>> temp;
            for(int j = 0; j < c; j ++)
            {
                if(temp[j] == '.')
                {
                    map[i][j] = 1;
                }
                else
                {
                    map[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < h; i ++)
        {
            num[i][0] = 0;
            for(int j = 1; j < c; j ++)
            {
                if(map[i][j] && map[i][j - 1])
                    num[i][j] = num[i][j - 1] + 1;
                else
                    num[i][j] = num[i][j - 1];
            }
        }
//        for(int i = 0;i < h; i ++)
//        {
//            for(int j =0; j< c; j ++)
//                printf("%d ", num[i][j]);
//            printf("\n");
//        }
        for(int i = 0; i < c; i ++)
        {
            num0[0][i] = 0;
            for(int j = 1; j < h; j ++)
            {
                if(map[j][i] && map[j - 1][i])
                    num0[j][i] = num0[j - 1][i] + 1;
                else
                    num0[j][i] = num0[j - 1][i];
            }
        }

        scanf("%d", &t);
        ans = 0;
        while(t --)
        {
            ans = 0;
            scanf("%d%d%d%d", &a, &b, &c0, &d);
            a --, b --, c0 --, d --;
            for(int i = a; i <= c0; i ++)
            {
                ans += num[i][d] - num[i][b];
                //printf("%d %d\n", num[i][d], num[i][b]);
            }
            for(int i = b; i <= d; i ++)
            {
                ans += num0[c0][i] - num0[a][i];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
