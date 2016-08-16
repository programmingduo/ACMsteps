#include<cstdio>
#include<string.h>

int is[7000], ans[3000];

int main ()
{
    int T, a;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &a);
        memset(is, 0, sizeof(is));
        for(int i = 3 * a + 17, total = 0; total < a; total ++)
        {
            if(i < 0)
            {
                printf("wrongans\n");
                break;
            }
            while(is[i])
            {
                i --;
                if(i < 0)
                {
                    printf("wrong ans\n");
                    break;
                }
            }
            ans[total] = i;
            is[i] = 1;
            i --;
            int temp = i + 1;
            for(int j = total - 1; j >= 0; j --)
            {
                temp += ans[j];
                if(temp > 3 * a + 17)
                    break;
                is[temp] = 1;
            }
        }
        for(int i = 0; i < a; i ++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
