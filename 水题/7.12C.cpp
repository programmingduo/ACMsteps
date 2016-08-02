#include<cstdio>
#include<algorithm>

int a[10005];

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }
        std::sort(a, a + n);
        int ans = 0;
        for(int i = n - 1; i >= 3; i --)
        {
            if(a[i] + a[i - 1] > a[i - 2] + a[i - 3] && a[i] < a[i - 1] + a[i - 2] + a[i - 3])
            {
                ans = i;
                break;
            }

        }
        if(ans)
            printf("%d\n", a[ans] + a[ans - 1] + a[ans - 2] + a[ans -3]);
        else
            printf("-1\n");
    }
    return 0;
}
