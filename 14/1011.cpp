#include<cstdio>
#include<string.h>ŝ

char s[100005];
int a[30];

int main ()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        scanf("%s", s);
        memset(a, 0, sizeof(a));
        int len = strlen(s);
        for(int i =0; i < len; i ++)
        {
            a[s[i] - 'a'] ++;
        }
        int ans  =0 ;
        for(int i = 0; i < 26; i ++)
        {
            if(a[i])
                ans ++;
        }

        printf("Case #%d: %d\n",t,  ans);
    }
}
