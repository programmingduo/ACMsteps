#include<cstdio>
#include<string.h>

int is[100009];
int ans[3000];

int main()
{
    int T,a,now,total;
    long long temp;
    scanf("%d", &T);
    memset(is, 0, sizeof(is));
    a = 2007;
    now = 1;
    total = 0;
    for(int i = 0; i < a; i ++)
    {
        while(is[now])
        {
            now ++;
        }
            is[now] = 1;
            ans[total] = now;
            temp = now;
//            printf("temp ");
        for(int j = total - 1; j >= 0; j --)
        {
            temp += ans[j];
//               printf("%d ",temp);
            if(temp > 3 * a + 18)
                break;
            is[temp] = 1;
        }
//           printf("\n");
        total ++;
        now ++;
    }
    while(T --)
    {
        scanf("%d", &a);

        for(int i = 0; i < a; i ++)
        {
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        if(ans[a - 1] > 3 * a + 18)
        {
            printf("wrong answer\n");
            break;
        }
//        printf("%d\n", temp);
    }
}
