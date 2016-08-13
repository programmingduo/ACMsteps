#include<cstdio>
#include<string.h>

char s1[100005], s2[100005];
int a[100], b[100];

int abs(int x)
{
    if(x >= 0)
        return x;
    return -x;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int ans = 0;
        scanf("%s%s", s1, s2);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int len1 = strlen(s1);
        for(int i = 0; i < len1; i ++)
        {
            a[s1[i] - 'a'] ++;
        }
        len1 = strlen(s2);
        for(int i = 0; i < len1; i ++)
        {
            b[s2[i] - 'a'] ++;
        }
        for(int i = 0; i < 26; i ++)
        {
            ans += abs(a[i] - b[i]);
        }
        printf("%d\n", ans);
    }
}
