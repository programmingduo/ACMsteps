#include<cstdio>
#include<string.h>
#include<cstring>

char c[30005], s[10005];
int r[40004], ansmax, ansid;

int min(int a, int b)
{
    return a< b? a: b;
}

void pre()
{
    int len = strlen(s);
    int k = 1;
    c[0] = '$';
    for(int i = 0; i < len; i ++)
    {
        c[k ++] = '#';
        c[k ++] = s[i];
    }
    c[k ++] = '#';
    c[k] = '\9';
}

void manachar()
{
    memset(r, 0, sizeof(r));
    int mx = 0, n = strlen(c), id;
    int maxx = 0;
    ansmax = 0;
    for(int i = 1; i < n; i ++)
    {
        if(mx > i)
            r[i] = min(r[2 * id - i], mx - i);
        else
            r[i] = 1;
        while(c[i - r[i]] == c[i + r[i]])
            r[i] ++;
        if(r[i] > ansmax + 1)
        {
            ansmax = r[i] - 1;
            ansid = i;
        }
        if(i + r[i] > mx)
        {
            mx = i + r[i];
            id = i;
        }
    }
}

int main()
{
    while(~scanf("%s", s))
    {
        pre();
        manachar();
        for(int i = ansid - ansmax; i < ansid + ansmax; i ++)
        {
            if(c[i] == '#' || c[i] == '$')
                continue;
            printf("%c", c[i]);
        }
        printf("\n");
//        printf("%d %d\n", ansid, ansmax);
//        for(int i = ansid - ansmax; i < ansid+ansmax; i ++)
//            printf("%c", s[i]);
//        printf("\n");
    }
    return 0;
}
