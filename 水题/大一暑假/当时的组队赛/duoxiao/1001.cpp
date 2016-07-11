#include<cstdio>
#include<string.h>

using namespace std;

int dp[100007];

int main ()
{
    int temp[10], flag = 0;
    dp[0] = 1, dp[1] = 2, dp[2] = 3;
    for(int k = 1; k < 100005; k ++)
    {
        int i = k;
        memset(temp, 0, sizeof(temp));
        flag = 0;
        while(i != 0)
        {
            if(temp[i % 10])
            {
                flag = 1;
                break;
            }
            temp[i % 10] ++;
            i /= 10;
        }
        if(!flag)
        {
            dp[k] = dp[k - 1] + 1;
        }
        else
            dp[k] = dp[k - 1];
    }

    int T, a, b;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", dp[b] - dp[a - 1]);
    }
    return 0;
}
