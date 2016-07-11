#include<cstdio>

int main ()
{
    int T, N, num, first, last, temp, ans, total;
    scanf("%d", &T);
    for(int i = 1; i <= T; i ++)
    {
        scanf("%d", &N);
        scanf("%d", &num);
        if(N == 1)
        {
            printf("Case %d:\n", i);
            printf("%d 1 1\n", num);
            continue;
        }
        first = 0;
        ans = num;
        temp = 0;
        total = num;
        if(num < 0)
        {
            total = 0;
            last = 0;
            ans = num;
            temp = 1;
        }
        for(int j = 1; j < N; j ++)
        {
            scanf("%d", &num);
            total += num;
            if(total > ans)
            {
                ans = total;
                first = temp;
                last = j;
            }
            if(total < 0)
            {
                temp = j + 1;
                total = 0;
            }
        }
        if(i > 1)
            printf("\n");
        printf("Case %d:\n", i);
        printf("%d %d %d\n", ans, first + 1, last + 1);
        continue;
    }
    return 0;
}
