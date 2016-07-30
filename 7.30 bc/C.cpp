#include<cstdio>
#include<set>
#include<cmath>
#include<string.h>
#include<algorithm>

using namespace std;

const long long N = 10000;
long long a[100000], titi[N];
long long prime[10000000];
set<long long> a_set;
set<long long>::iterator it, it2;

void Prime()
{
    memset(a, 0, sizeof(a));
    int num = 0;
    a[0] = a[1] = 1;
    a_set.clear();
    for(int i = 2; i < N; i ++)
    {
        if(!a[i])
        {
            it = a_set.begin();
            int total = 0;
            while(it != a_set.end())
            {
                printf("a");
                titi[total ++] = i * (*it);
                it ++;
            }
            a_set.insert(i);
            for(int j = 0; j < total; j ++)
            {
                a_set.insert(titi[j]);
            }
            prime[num ++] = i;
        }
        for(int j = 0; j < num && i * prime[j] < N; j ++)
        {
            a[i * prime[j]] = 1;
            if(!(i % prime[j]))
                break;
        }
    }
}

int main ()
{
    int T;
    long long num;
    scanf("%d", &T);
    Prime();
    printf("a\n");
    while(T -- )
    {
    printf("a\n");
        scanf("%I64d", &num);
        long long temp = sqrt(num);
        it = a_set.lower_bound(temp);
        long long ans = abs((*it) * (*it) - num);
        it ++;
        ans = min(ans, abs((*(it)) * (*(it)) - num));
        printf("%I64d\n", ans);
    }
    return 0;
}
