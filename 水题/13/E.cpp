#include<cstdio>
#include<string.h>

char s[100005], small[100005], big[100005];

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%s", s);
        scanf("%d", &n);
        int total = n, last1 = 0, last2 = 0;
        int len = strlen(s);
        for(int i = 0; i < len; i ++)
        {
            while(total && last1 && s[i] < small[last1 - 1])
            {
                last1 --;
                total --;
            }
            small[last1 ++] = s[i];
        }
        last1 -= total;
//        for(int i = 0; i < last1; i ++)
//        {
//            printf("%c", small[i]);
//        }
//        printf("\n");
        total = n;
        for(int i = 0; i < len; i ++)
        {
            while(total && last2 && s[i] > big[last2 - 1])
            {
                last2 --;
                total --;
            }
            big[last2 ++] = s[i];
        }
        last2 -= total;
        for(int i = 0; i < last1; i ++)
        {
            printf("%c", small[i]);
        }
        printf("\n");
        for(int i = 0; i < last2; i ++)
        {
            printf("%c", big[i]);
        }
        printf("\n");
    }
    return 0;
}
