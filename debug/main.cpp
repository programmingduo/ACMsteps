#include<cstdio>
#include<string.h>

#define maxn 200010
int wa[maxn], wb[maxn], wsf[maxn], wv[maxn], sa[maxn];
int rank[maxn], height[maxn], s[maxn];
char str[maxn], str1[maxn];

int cmp(int *r, int a, int b, int k)
{
    return r[a] == r[b] && r[a+k] == r[b+k];
}

void getsa(int *r, int *sa, int n, int m)
{
    int *x = wa, *y = wb, *t, i, j, p;
    for(i = 0; i < m; i ++) wsf[i] = 0;
    for(i = 0; i < n; i ++) wsf[x[i] = r[i]] ++;
    for(i = 1; i < m; i ++) wsf[i] += wsf[i - 1];
    for(i = n - 1; i >= 0; i --) sa[--wsf[x[i]]] = i;

    p = 1;
    j = 1;
    for(; p < n; j *= 2, m = p)
    {
//        printf("%d", p);
        for(p = 0, i = n - j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j ) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wsf[i] = 0;
        for(i = 0; i < n; i ++) wsf[wv[i]] ++;
        for(i = 1; i < m; i ++) wsf[i] += wsf[i - 1];
        for(i = n - 1; i >= 0; i --) sa[--wsf[wv[i]]] = y[i];
        t = x;
        x = y;
        y = t;
        x[sa[0]] = 0;
        for(p = 1, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)? p - 1: p ++;
    }
}

void getheight(int *r, int n)
{
    int i, j, k =0;
    for(i = 1; i <= n; i ++)
        rank[sa[i]] = i;
    for(i = 0; i < n; i ++)
    {
        if(k)
            k --;
        j = sa[rank[i] - 1];
        while(r[i + k] == r[j + k])
            k ++;
        height[rank[i]] = k;
    }
}

int main ()
{
    while(~scanf("%s", str))
    {
        scanf("%s", str1);
        int n = 0, len = strlen(str);
        for(int i = 0; i < len; i ++)
        {
            s[n ++] = str[i] - 'a' + 1;
        }
        s[n ++] = 28;
        len = strlen(str1);
        for(int i = 0; i < len; i ++)
            s[n ++] = str1[i] - 'a' + 1;
        s[n] = 0;
        getsa(s, sa, n + 1, 30);
        getheight(s, n);

        int maxx = 0, pos = 0;
        len = strlen(str);
        for(int i = 2; i < n; i ++)
            if(height[i] > maxx)
            {
                if(0 <= sa[i - 1] && sa[i - 1] < len && len < sa[i])
                    maxx = height[i];
                if(0 <= sa[i] && sa[i] < len && len < sa[i - 1])
                    maxx = height[i];
            }
        printf("%d\n", maxx);
    }
}
