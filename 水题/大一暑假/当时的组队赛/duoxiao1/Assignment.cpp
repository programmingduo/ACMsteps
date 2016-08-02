#include<cstdio>

using namespace std;

int main ()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i ++)
    {
        long long n, k, a[100000], num = 0;
        scanf("%lld%lld", &n, &k);
        for(int j = 1; j <= n; j ++)
        {
            scanf("%d", &a[j]);
        }

        long long min = a[1], minid = 1, max = a[1], maxid = 1, flag = 1, flag0 = 0, ans = 0;
        for(int j = 1; j <= n; j ++)
        {
            for(int jj = j; jj <= n; jj ++)
            {
                if(a[jj] <= min)
                {
                    flag = 1;
                    min = a[jj];
                    minid = jj;
                }
                else if(a[jj] >= max)
                {
                    flag = 2;
                    max = a[jj];
                    maxid = jj;
                }

                if(max - min >= k)
                {
                    long long down, up;
                    if(minid >= maxid)
                    {
                        up = minid - j;
                        down = minid - maxid;
                        maxid ++;
                        max = a[maxid];
                        j = maxid - 1;
                    }
                    else
                    {
                        up = maxid - j;
                        down = maxid - minid;
                        minid ++;
                        min = a[minid];
                        j = minid - 1;
                    }

                    for(int jjj = down; jjj <= up; jjj ++)
                    {
                        ans += jjj;
                    }
                    break;
                }
                else if(jj == n)
                {
                    flag0 = 1;
                    for(int jjj = 1; jjj <= n - j + 1; jjj ++)
                        ans += jjj;
                    break;
                }
            }
            if(flag0 == 1)
            {
                break;
            }
        }

        printf("%lld\n", ans);
    }
}
