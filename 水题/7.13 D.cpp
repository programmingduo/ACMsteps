#include<cstdio>
#include<algorithm>

int a[200005];

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        int flag =0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            a[i] += i;
        }
        std::sort(a, a + n);
        for(int i = 0; i < n; i ++)
            a[i] -= i;
        for(int i = 0; i < n; i ++)
            if(a[i] < a[i - 1])
        {
            printf(":(\n");
            flag = 1;
            break;
        }
        if(flag )
            continue;
        for(int i = 0; i < n; i ++)
            if(i)
            printf(" %d", a[i]);
        else
            printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}
