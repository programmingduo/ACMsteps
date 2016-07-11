#include<cstdio>
#include<algorithm>

using namespace std;

long long a[100005], b[100005], cost[100005];

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++)
            scanf("%lld%lld", &a[i], &b[i]);
        cost[n - 1] = a[n - 1] * b[n - 1];
        for(int i = n - 2; i >= 0; i --)
        {
            cost[i] = min(a[i] * b[i], cost[i + 1]);
        }

        int l = 0, r = n - 1;
        long long q;
        for(int i = 0; i < m; i ++)
        {
            scanf("%lld", &q);
            if(q >= a[n - 1])
            {
                printf("%lld\n", q * b[n - 1]);
                continue;
            }
            l = 0, r = n - 1;
            while(r - l > 1)
            {
                int mid = (l + r) >> 1;
                if(a[mid] > q)
                    r = mid;
                else if(a[mid] == q)
                    r = l = mid;
                else
                    l = mid;
            }
//            if(!(a[l] <= q && a[r] >= q))
//                while(1)
//                q ++;
            if(q == a[l])
                printf("%lld\n", cost[l]);
            else
                printf("%lld\n", min(q * b[l], cost[l + 1]));
        }
    }
}
