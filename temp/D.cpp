#include<cstdio>

char s[10032];

int main ()
{
    int T, len;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &len);
        scanf("%s", &s);
        int now = 0, ans = 0;
        for(int i = 0; i < len; i ++)
        {
            if(s[i] == '(')
            {
                now ++;
            }
            else
            {
                if(now == 0)
                {
                    ans ++;
                    now = 1;
                }
                else
                    now --;
            }
        }
        printf("%d\n", ans + now / 2);
    }
    return 0;
}
