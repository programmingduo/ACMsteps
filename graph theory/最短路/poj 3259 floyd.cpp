#include<cstdio>

int min(int a, int b)
{
    return a < b? a: b;
}

int w[1000][1000];

int main ()
{
    int T;
    scanf("%d", &T);
    int N, M, W, a, b, c;
    while(T --)
    {
        scanf("%d%d%d", &N, &M, &W);
        for(int i = 0; i <= N; i ++)
            for(int j = 0; j <= N; j ++)
                if(i == j)
                    w[i][j] = 0;
                else
                    w[i][j] = 0x3fffffff;
        for(int i = 0; i < M; i ++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(w[a][b] > c)
                w[a][b] = w[b][a] = c;
        }
        for(int i = 0; i < W; i ++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(w[a][b] > -c)
                w[a][b] = -c;
        }
        int flag = 0;
        for(int k = 1; k <= N && !flag; k ++)
        {
            for(int i = 1; i <= N && !flag; i ++)
            {
                for(int j = 1; j <= N && !flag; j ++)
                {
                    int t=w[i][k]+w[k][j];
                    if(w[i][j]>t)w[i][j]=t;
                    //用下面的方式就会t。。。。
//                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
                }
                if(w[i][i] < 0)
                    flag = 1;
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
