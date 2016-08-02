#include<cstdio>
#include<string.h>
char s[10005], c[10005];
int next[10005];

void pre()
{
    int len = strlen(c);
    next[0] = next[1] = 0;
    for(int i = 2; i <= len; i ++)
    {
        int j = next[i - 1];
        while(j && c[i - 1] != c[j])
            j = next[j];
        next[i] = c[i - 1] == c[j]? j + 1: 0;
    }
//    for(int i = 0; i <= len; i ++)
//        printf("%d ", next[i]);
//    printf("\n");
}

int solve()
{
    int len1 = strlen(s), len2 = strlen(c), j = 0, ans =0 ;
    for(int i = 0; i < len1; i ++)
    {
        if(s[i] == c[j])
            j ++;
        else
        {
            while(j && s[i] != c[j])
                j = next[j];
            if(s[i] == c[j])
                j ++;
        }
        if(j == len2)
        {
            j = 0;
            ans ++;
        }
    }
    return ans;
}

int main ()
{
    while(~scanf("%s", s))
    {
//        printf("%s ", s);
        if(strcmp(s, "#") == 0)
            break;
        scanf("%s", c);
        pre();
        printf("%d\n", solve());
    }
    return 0;
}
