#include<cstdio>
#include<cstring>

int main ()
{
    int T;
    scanf("%d", &T);
    char c[1005];
    for(int i = 1; i <= T; i ++)
    {
        int ans = 0;
        scanf("%s", c);
        for(int j = 1; j < strlen(c); j ++)
        {
            int k = j - 1, temp = 0;
            while(k >= 0)
            {
                temp = temp ^ c[k] ^ c[k + 1];
                if(temp == 0)
                    ans ++;
                k -= 2;
            }
        }
        printf("1 %d\n", ans);
        for(int j = 1; j < strlen(c); j ++)
        {
            int a = j - 1, b = j + 1, temp = 0;
            while(a >= 0 && b < strlen(c))
            {
                temp = temp ^ c[a] ^ c[b];
                a --, b ++;
                if(temp == 0)
                    ans ++;
            }
        }
        printf("2 %d\n", ans);
        ans += strlen(c);
        printf("%d\n", ans);
    }
    return 0;
}
