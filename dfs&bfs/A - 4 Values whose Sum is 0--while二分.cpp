#include<cstdio>
#include<algorithm>

using namespace std;

int num[4][4004], sum[16000005];

int main ()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i  ++)
        for(int j = 0; j < 4; j ++)
            scanf("%d", &num[j][i]);

    int temp = 0;
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
        sum[temp ++] = num[0][i] + num[1][j];

    sort(sum, sum + temp);
    int ans = 0;
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
        {
            int sum1 = num[2][i] + num[3][j];
            sum1 = -sum1;
            int first = 0, last = temp - 1;
            while(first <= last)          //此处还有=
            {
                int mid = (first + last) >> 1;
                if(sum[mid] > sum1)
                    last = mid - 1;
                else if(sum[mid] < sum1)
                    first = mid + 1;
                else
                {
                    ans ++;
                    for(int k = mid - 1; k >= first; k --)
                    {
                        if(sum[k] == sum1)
                            ans ++;
                        else
                            break;
                    }
                    for(int k = mid + 1; k <= last; k ++)
                    {
                        if(sum[k] == sum1)
                            ans ++;
                        else
                            break;
                    }
                    break;
                }
            }
        }
    printf("%d\n", ans);

    return 0;
}
