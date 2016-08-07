#include<cstdio>
#include<string.h>

int a[10000];
char s[100005], str[3];

int main ()
{
    int n;
    scanf("%s", s);
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i =0; i < n; i ++)
    {
        scanf("%s", str);
        int t = (str[0] - 'a') * 100 + str[1] - 'a';
        a[t] = 1;
        t = (str[1] - 'a') * 100 + str[0] - 'a';
        a[t] = 1;
    }
    int len = strlen(s) - 1, ans  =0;
    for(int i = 0; i < len; i ++)
    {
        int temp = (s[0] - 'a') * 100 + s[1] - 'a';
        if(a[temp])
        {
            int l = i, r = i + 1;
            while(1)
            {
                ans ++;
                if(l == 0 || r == len)
                    break;
                if(s[l - 1] != s[l] || s[r] != s[r + 1])
                    break;
                l --, r ++;
            }
            i = r;
        }
    }
    printf("%d\n", ans);
    return main();
}
