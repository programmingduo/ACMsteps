#include <cstdio>
#include <string.h>

char s[100055];
int firstu[100004], firstd[100004], firstl[100004], firstr[100004];

int min(int a, int b)
{
    return a < b? a: b;
}

int min(int a, int b, int c, int d, int len)
{
    int re = len;
    if(firstu[a])
        re = min(re, firstu[a]);
    if(firstd[b])
        re = min(re, firstd[b]);
    if(firstl[c])
        re = min(re, firstl[c]);
    if(firstr[d])
        re = min(re, firstr[d]);
    return re;
}

int main ()
{
    while(~scanf("%s", s))
    {
        int len = strlen(s), d = 0, r = 0, l = 0, u = 0, q, x, y, n, m;
        memset(firstu, 0, sizeof(firstu));
        memset(firstl, 0, sizeof(firstl));
        memset(firstd, 0, sizeof(firstd));
        memset(firstr, 0, sizeof(firstr));
        for(int i = 0; i < len; i ++)
        {
            if(s[i] == 'u')
            {
                u ++;
                d --;
                if(u > 0 && !firstu[u])
                    firstu[u] = i + 1;
            }
            if(s[i] == 'd')
            {
                d ++;
                u --;
                if(d > 0 && !firstd[d])
                    firstd[d] = i + 1;
            }
            if(s[i] == 'l')
            {
                l ++;
                r --;
                if(l > 0 && !firstl[l])
                    firstl[l] = i + 1;
            }
            if(s[i] == 'r')
            {
                r ++;
                l --;
                if(r > 0 && !firstr[r])
                    firstr[r] = i + 1;
            }
        }
        scanf("%d", &q);
        while(q --)
        {
            scanf("%d %d %d %d", &n, &m, &x, &y);
            printf("%d\n", min(x, n - x + 1, y, m - y + 1, len));
        }
    }
}
