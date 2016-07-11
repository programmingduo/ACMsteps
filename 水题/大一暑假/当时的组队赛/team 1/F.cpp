#include<cstdio>
#include<algorithm>


using namespace std;

long long fight[100005];

int main ()
{
    long long N, M;
    while(~scanf("%lld%lld", &N, &M))
    {
        int flag = 0;
        for(long long i = 0; i < N; i ++)
            scanf("%d", &fight[i]);
        sort(fight, fight + N);
        int n = unique(fight, &fight[N - 1]) - fight + 1;
        for(long long i = 0; i < n; i ++)
        {
            for(long long j = n - 1; j > i; j --)
            {
                long long sum = fight[i] ^ fight[j];
                if(sum > M)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
