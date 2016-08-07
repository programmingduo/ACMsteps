#include<cstdio>
#include<map>
using namespace std;

map<long long, int> m;
long long w[1006], v[1005], u[1005];

int main ()
{
    int n, op, t = 0;
    long long a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &op);
        if(op == 1)
        {
            scanf("%lld %lld %lld", &v[t], &u[t], &w[t]);
            t ++;
        }
        else
        {
            scanf("%lld %lld", &a, &b);
            m.clear();
            while(a != b)
            {
                if(a > b)
                {
                    m[a] = 1;
                    a /= 2;
                }
                else
                {
                    m[b] = 1;
                    b /= 2;
                }
            }

            long long ans = 0;
            for(int j = 0; j < t; j ++)
            {
                a = v[j];
                b = u[j];
                while(a != b)
                {
                    if(a > b)
                    {
                        if(m.find(a) != m.end())
                            ans += w[j];
                        a /= 2;
                    }
                    else
                    {
                        if(m.find(b) != m.end())
                            ans += w[j];
                        b /= 2;
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}

