#include<cstdio>
#include<string.h>

char s[10000005];

int main ()
{
    int t  =1;
    while(~scanf("%s", s))
    {
        int len = strlen(s), ans = 0;
        for(int i = 0; i < len; i ++)
        {
            ans = ans * 10 + s[i] - '0';
            ans %= 10001;
        }
        if(ans)
            printf("Case #%d: NO\n", t);
        else
            printf("Case #%d: YES\n", t);
            t  ++;
    }
}
