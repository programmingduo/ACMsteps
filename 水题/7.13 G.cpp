#include<cstdio>
#include<algorithm>

int max (int x, int y)
{
    return x > y? x: y;
}

int a[10];

int main()
{
    while(~scanf("%d", &a[0]))
    {
        for(int i = 1; i < 5; i ++)
            scanf("%d", &a[i]);
        std::sort(a, a + 5);
        int ans = 0;
        for(int i = 0; i < 4; i ++)
        {
            if(a[i] == a[i + 1])
            {
                if(i < 4 && a[i + 2] == a[i])
                    ans = max(ans, a[i] * 3);
                else
                    ans = max(ans, a[i] * 2);
            }
        }
        int total = 0;
        for(int i = 0; i < 5; i ++)
            total += a[i];
        if(ans)
            printf("%d\n", total - ans);
        else
        {
                printf("%d\n", total);
        }
    }
    return 0;
}
