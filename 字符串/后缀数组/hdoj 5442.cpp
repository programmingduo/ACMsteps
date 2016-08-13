#include<cstdio>
#include<cstring>
#include<string.h>
const int maxn = 100005;

int wa[maxn], wb[maxn], wsf[maxn], wv[maxn], sa[maxn];
int rank[maxn], height[maxn], s[maxn];
char str[maxn], str1[maxn];

int cmp(int *r, int a, int b, int k)
{
    return r[a] == r[b] && r[a + k] == r[b + k];
}

void get_sa(int *r, int *sa, int n, int m)
{
    int *x = wa, *y = wb, *t, i, j, p;
    for(i = 0; i < m; i ++) wsf[i] = 0;
    for(i = 0; i < n; i ++) wsf[x[i] = r[i]] ++;
    for(i = 1; i < m; i ++) wsf[i] += wsf[i - 1];
    for(i = n - 1; i >= 0; i --) sa[-- wsf[x[i]]] = i;

    p = 1, j = 1;
    for(; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n - j; i < n; i ++) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wsf[i] = 0;
        for(i = 0; i < n; i ++) wsf[wv[i]] ++;
        for(i = 1; i < m; i ++) wsf[i] += wsf[i - 1];
        for(i = n - 1; i >= 0; i --) sa[--wsf[wv[i]]] = y[i];
        t = x;
        x = y;
        y = t;
        x[sa[0]] = 0;
        for(p = 1, i = 1; i < n; i ++)
            x[sa[i]] == cmp(y, sa[i - 1], sa[i], j)? p - 1: p ++;
    }
}

void getheight(int *r, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i++)
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


int main()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        scanf("%s", str);
        strcpy(str1, str);
        strcat(str1, str1);
        for(int i = 0; i < n; i ++)
            str[i] = str1[n - 1 - i];
        strcat(str, str);
        n *= 2;
        for(int i = 0; i < n; i ++)
        {
            s[i] = str[i] - 'a';
        }
        s[n ++] = 28;

//        for(int i = 0; i < strlen(str1); i ++)
//            printf("%c", str1[i]);
//        printf("\n");
//        for(int i = 0; i < strlen(str); i ++)
//            printf("%c", str[i]);
//        printf("\n");

        get_sa(s, sa, n + 1, 30);
        getheight(s, n);
        for(int i = 0; i < n; i ++)
        {
            if(height[i] == n / 2)
            {
                ans = i;
                break;
            }
        }

    }
    return 0;
}
