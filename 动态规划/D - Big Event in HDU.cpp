#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 100000;

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n < 0)     //�Ǻǣ���˵��С���㣬��Ϊʲô�ͷ�Ҫд����-1
            break;
        int tempv, tempn, sum = 0;
        int w[maxn], N = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &tempv, &tempn);
            int temp = N + tempn;
            for(; N < temp; N ++)
            {
                w[N] = tempv;
                sum += tempv;
            }
        }

        int dp[maxn];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i ++)
        {
            for(int j = sum / 2; j >= w[i]; j --)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + w[i]);    //����Ϊw[i],��ֵΪw[i]
            }
        }
        int temp = dp[sum / 2];
        printf("%d %d\n", sum - temp, temp);
    }
    return 0;
}
