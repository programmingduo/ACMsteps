#include<cstdio>
#include<vector>

using namespace std;

const long long mod = 1000000007;
vector<int> v[1000005];
int temp[1000005], a[1000005];

long long multi(long long a, long long b)
{
    long long ret;
    ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret  = ret * a % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return ret;
}

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            v[i].clear();
        }
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            v[a[i]].push_back(i);
        }
        int length = 0;
        long long tempans = 0;
        long long x = multi(2, n);
        long long tempx = x;
        x = (x * (n - 2) + 2) % mod;
        for(int i = 1; i <= n; i ++)
        {
            if(v[i].size() <= 1)
                continue;
            length = 0;
            tempans = 0;
            for(int j = 0; j < v[i].size(); j ++)
            {
                temp[length ++] = v[i][j];
            }
            while(length > 1)
            {

                for(int j = 0; j < length - 1; j ++)
                {
                    tempans += multi(2, n - (temp[length - 1] - temp[j]));
                    tempans %= mod;
                }
                length --;
            }
        }
        long long ans = x - tempans;
        while(ans < 0)
            ans += mod;
        printf("%lld\n", ans);
    }
    return 0;
}
