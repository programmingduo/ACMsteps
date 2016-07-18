//#include<cstdio>
//#include<string.h>
//
//int dp[1006][105];
//int t[105], v[106];
//
//inline int max(int a, int b)
//{
//    return a> b? a: b;
//}
//
//int main ()
//{
//    int T, N, M, L;
//    scanf("%d", &T);
//    while(T --)
//    {
//        scanf("%d%d%d", &N, &M, &L);
//        for(int i = 0; i < N; i ++)
//        {
//            scanf("%d%d", &t[i], &v[i]);
//        }
//
//        memset(dp, 0, sizeof(dp));
//
//
//        for(int j = 0; j < N; j ++)
//        {
//            for(int k = 1; k <= M; k ++)
//            {
//                for(int i = L; i >= L - t[j]; i --)
//                {
//                    dp[i][k] = max(dp[i][k], dp[i - t[j]][k - 1] + v[j]);
//                }
//            }
//        }
//
//        int ans = 0;
//        for(int i = 0; i <= L; i ++)
//            for(int j = 0; j <= M; j ++)
//            ans = max(ans, dp[i][j]);
//        printf("%d\n", ans);
//    }
//    return 0;
//}

#include<iostream>
#include<cstdio>
//#include
using namespace std;
#define INF 0x7fffffff

int dp[110][1010];
int a[110],b[110];
int n,m,l;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&l);
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=l; j++)
                dp[i][j] = -INF;
        }
        for(int i=0; i<=l; i++)//选0个电影时价值为0.。。
            dp[0][i] = 0;
        for(int i=1; i<=n; i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=m; j>=1; j--)
            {
                for(int k=l; k>=a[i]; k--)
                {
                    dp[j][k] = max(dp[j][k],dp[j-1][k-a[i]]+b[i]);
                }
            }
        }
        if(dp[m][l] > 0)
            printf("%d\n",dp[m][l]);
        else
            printf("0\n");
    }
    return 0;
}
