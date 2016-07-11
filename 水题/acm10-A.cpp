#include<cstdio>
#include<algorithm>

int a[100005], b[100005];

int main ()
{
    int n, m, k;
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        for(int i = 0; i <n; i ++)
            scanf("%d", &a[i]);
        for(int i = 0; i <m; i ++)
            scanf("%d", &b[i]);
        if(n > m)
        {
            printf("YES\n");
            continue;
        }
        std::sort(a, a + n);
        std::sort(b, b + m);
        int flag = 0;
        for(int i = 1; i <= n; i ++)
        {
            int x = n - i;
            int y = m - i;
            if(a[x] > b[y])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
