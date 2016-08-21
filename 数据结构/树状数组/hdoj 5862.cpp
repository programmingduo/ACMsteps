#include<cstdio>
#include<string.h>
#include<algorithm>
#include<map>

using namespace std;

const int maxn = 100005;
int x1[maxn], x2[maxn], y1[maxn], y2[maxn], c[maxn * 4];
int total;

struct node1
{
    int x, y, val, y1, y2;
}heng[maxn * 2];

int cmp1(node1 xx, node1 yy)
{
    if(xx.x == yy.x)
        return xx.val > yy.val;
    return xx.x < yy.x;
}

inline int lowbit(int x)
{
    return x & -x;
}

inline void add(int i, int val)
{
    while(i <= total)
    {
        c[i] += val;
        i += lowbit(i);
    }
}

inline int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}

map<int, int> x, y;
map<int, int >::iterator it;

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        x.clear();
        y.clear();
        for(int i = 0; i < n; i ++)
        {
            scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
            if(x1[i] > x2[i])
                swap(x1[i], x2[i]);
            if(y1[i] > y2[i])
                swap(y1[i], y2[i]);
            x[x1[i]] ++;
            y[y1[i]] ++;
            x[x2[i]] ++;
            y[y2[i]] ++;
        }

        total = 1;
        for(it = x.begin(); it != x.end(); it ++)
            it->second = total ++;
        total = 1;
        for(it = y.begin(); it != y.end(); it ++)
            it->second = total ++;

        for(int i = 0; i < n; i ++)
        {
            x1[i] = x[x1[i]];
            x2[i] = x[x2[i]];
            y1[i] = y[y1[i]];
            y2[i] = y[y2[i]];
        }

        int total1 = 0;
        for(int i = 0; i < n; i ++)
        {
            if(y1[i] == y2[i])
            {
                heng[total1].x = x1[i];
                heng[total1].y = y1[i];
                heng[total1 ++].val = 1;
                heng[total1].x = x2[i];
                heng[total1].y = y2[i];
                heng[total1 ++].val = -1;
            }
            else
            {
                heng[total1].x = x1[i];
                heng[total1].y1 = y1[i];
                heng[total1].y2 = y2[i];
                heng[total1 ++].val = 0;
            }
        }

        sort(heng, heng + total1, cmp1);
        memset(c, 0, sizeof(c));
        long long ans = 0;
        for(int i = 0; i < total1; i ++)
        {
            if(heng[i].val == 0)
                ans += sum(heng[i].y2) - sum(heng[i].y1 - 1);
            else
                add(heng[i].y, heng[i].val);
        }
        printf("%I64d\n", ans);
    }
}
