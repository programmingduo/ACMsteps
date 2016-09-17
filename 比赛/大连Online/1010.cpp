#include<cstdio>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

int head[200010], nextt[200010], to[200010], s[200010], notfa[200010];
long long a[200010], ans, n, k;
int total, maxx;
map<long long, int> ma;

int lowbit(int x)
{
    return x&(-x);
}
void add(int x, int val)
{
    for(int i = x; i <= maxx; i +=lowbit(i))
        s[i] += val;
}
int sum(int x)
{
    int re = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        re += s[i];
    return re;
}

void dfs(int u)
{
    long long temp = k / a[u];
    if(temp * a[u] == k)
        ans += sum(ma[temp] - 1);
    else
        ans += sum(ma[temp]);
    add(ma[a[u]], 1);
    for(int i = head[u]; i != -1; i = nextt[i])
    {
        int v = to[i];
        dfs(v);
    }
    add(ma[a[u]], -1);
}

void add_edge(int l, int r)
{
    to[total] = r;
    nextt[total] = head[l];
    head[l] = total ++;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        memset(head, -1, sizeof(head));
        memset(notfa, 0, sizeof(notfa));
        memset(s, 0, sizeof(s));
        ma.clear();
        total = 0;
        ans = 0;

        scanf("%I64d %I64d", &n, &k);
        for(int i= 1; i <= n; i ++)
        {
            scanf("%I64d", &a[i]);
            ma[a[i]] ++;
            ma[k / a[i]] ++;
        }

        map<long long, int>::iterator it = ma.begin();
        for(int i = 1; it != ma.end(); it ++, i ++)
        {
            it->second = i;
            maxx = i;
        }

        int l, r;
        for(int i = 1; i < n; i ++)
        {
            scanf("%d %d", &l, &r);
            notfa[r] = 1;
            add_edge(l, r);
        }

        for(int i = 1; i <= n; i ++)
        {
            if(!notfa[i])
            {
                dfs(i);
                break;
            }
        }

        printf("%I64d\n", ans);
    }
}
