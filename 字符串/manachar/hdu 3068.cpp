#include<cstdio>
#include<string.h>


char s[120000], c[250000];
int r[250000];

int min(int a, int b)
{
    return a < b? a: b;
}

int max(int a, int b)
{
    return a> b? a: b;
}

void pre()
{
    int len = strlen(s);
    int k =1;
    c[0] = '$';
    for(int i = 0; i < len; i ++)
    {
        c[k ++] = '#';
        c[k ++] = s[i];
    }
    c[k ++] = '#';
    c[k] = '\0';
//    printf("%s\n", c);
}

int manachar()
{
    memset(r, 0, sizeof(r));
    int mx = 0, id, maxx = 0, n = strlen(c);
    for(int i = 1; i < n; i ++)
    {
        if(mx > i)
            r[i] = min(r[2 * id - i], mx - i);
        else
            r[i] = 1;
        while(c[i - r[i]] == c[i + r[i]])
            r[i] ++;
        maxx = max(maxx, r[i]);
        if(i + r[i] > mx)
        {
            mx = i + r[i];
            id = i;
        }
//        printf("%d %d\n", i, r[i]);
    }
    return maxx - 1;
}

int main ()
{
    while(~scanf("%s", s))
    {
        pre();
        printf("%d\n", manachar());
    }
    return 0;
}
