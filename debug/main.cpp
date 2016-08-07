#include<cstdio>
#include<string.h>

int a[256000];
int min(int x, int y)
{
    return x<y? x: y;
}
char s[256005], str[3];

int main ()
{
    int n;
    scanf("%s", s);
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; i ++)
    {
        scanf("%s", str);
        int t = str[0] * 200 + str[1];
        a[t] = 1;
        t = str[1] * 200 + str[0] ;
        a[t] = 1;
    }
    int len = strlen(s) - 1, ans  =0;
    for(int i = 0; i < len; i ++)
    {
        int temp = (s[i]) * 200 + s[i + 1];
        if(a[temp])
        {
            int k;
            int t1 = 1, t2 = 1;
            for(k = i + 2; k <= len; k ++)
            {
                if(s[k] == s[i])
                    t1 ++;
                else if(s[k] == s[i + 1])
                    t2 ++;
                else
                    break;
            }
            for(int kk = i - 1; kk >= 0; kk --)
            {
                if(s[kk] == s[i])
                    t1 ++;
                else if(s[kk] == s[i + 1])
                    t2 ++;
                else
                    break;
            }
            ans += min(t1, t2);
            i = k - 1;
        }
    }
    printf("%d\n", ans);
    return main();
}
