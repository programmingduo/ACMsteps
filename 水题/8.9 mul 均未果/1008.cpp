#include<cstdio>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

int dp[1<<21], last[1<<21], can[1<<21], in[1 << 21];
int a[21], s1[1 << 22];
long long A[21];
queue<int> q;

void init()
{
    A[0] = 1;
    for(int i = 1; i < 21; i ++)
        A[i] = i * A[i - 1];

    memset(s1, 0, sizeof(s1));
    for(int i = 0; i <= 1 << 21; i ++)
    {
        int temp = i;
        while(temp)
        {
            s1[i] += temp % 2;
            temp >>= 1;
        }
    }
}

//long long gcd(long long a, long long b)
//{
//    if()
//}

int main ()
{

    int T, p, n, m;
    init();
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d %d", &p, &n, &m);
        for(int i = 0; i < m; i ++)
            scanf("%d", &a[i]);
        std::sort(a, a + m);
        int sum = 0;
        for(int i = 0; i < n * 2 && i < m; i ++)
            sum += a[i];
        if(sum < p)
        {
            printf("0/1\n");
            continue;
        }

        while(!q.empty())
            q.pop();
        int total = n + m;
        memset(dp, -1, sizeof(dp));
        memset(last, 0, sizeof(last));
        memset(can, 0, sizeof(can));
        memset(in, 0, sizeof(in));
        long long ans = 0;
        last[0] = 1;
        dp[0] = 0;
        can[0] = 1;
        q.push(0);
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            if(last[t] == 0 || s1[t] == total)
            {
                if(dp[t] >= p)
                {
                    ans += A[total - s1[t]] * can[t];
                }
                continue;
            }
            for(int i = 0; i < total; i ++)
            {

                if(t & 1 << i)
                    continue;

                int temp = t ^ (1 << i);
                if(in[temp])
                {
                    can[temp] += can[t];
                }
                else
                {
                    in[temp] = 1;
                    q.push(temp);
                    can[temp] = can[t];
                    if(i < m)
                    {
                        last[temp] = last[t] - 1;
                        dp[temp] = dp[t] + a[i];
                    }
                    else
                    {
                        last[temp] = last[t] + 1;
                        dp[temp] = dp[t];
                    }
                }
            }
        }
        if(ans == 0)
        {
            printf("0/1\n");
            continue;
        }
        long long t = A[total];
        long long g = std::__gcd(ans, t);
        t /= g;
        ans /= g;
        printf("%I64d/%I64d\n", ans, t);
    }
}
