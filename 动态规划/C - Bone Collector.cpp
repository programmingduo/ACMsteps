#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100000;
int N, V, v[maxn], w[maxn];

int bag()
{
    int f[100000];
    memset(f, 0, sizeof(f));
    for(int i = 0; i < N; i ++)
    {
        for(int j = V; j >= v[i]; j --)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    return f[V];
}

int main ()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i ++)
    {
        scanf("%d%d", &N, &V);
        for(int i = 0; i < N; i ++)
            scanf("%d", &w[i]);
        for(int i = 0; i < N; i ++)
            scanf("%d", &v[i]);

        int ans = bag();
        printf("%d\n", ans);
    }
}
