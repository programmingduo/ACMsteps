#include<cstdio>

int main ()
{
    int n, d1, d2, a[100000];
    while(~scanf("%d%d%d", &n, &d1, &d2))
    {
        int ans = 0, flag = 1, flag2 = 1, last = -1;
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);

        for(int i = 0; i < n; i ++)
        {
            if(i == last)
                continue;
            last = i;
            printf("i = %d\n", i);
            int ans1 = 1, ans2 = 0, j = i + 1;
            while(a[j] == a[j - 1] + d1 && j < n)
                ans1 ++, j ++;
            printf("j = %d\n", j);
            int k = j;
            while(a[k] == a[k - 1] + d2 && k < n)
                ans2 ++, k ++;

            for(int l = ans1 + ans2; l > 0; l --)
            {
                ans += l;
            }
            ans --;
            printf("ans1 = %d, ans2 = %d, ans = %d\n", ans1, ans2, ans);
            i = k - 2;
            if(i < 0)
                i ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
