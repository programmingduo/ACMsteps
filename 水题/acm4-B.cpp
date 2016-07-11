#include<cstdio>
#include<algorithm>

int a[200005];

int main ()
{
    int n, flag;
    while(~scanf("%d", &n))
    {
        flag = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            a[i] += i;
        }
        std::sort(a, a + n);
        for(int i = 0; i < n; i ++)
            a[i] = a[i] - i;
        for(int i = 1; i < n; i ++)
        {
            if(a[i] < a[i - 1])
                flag =  1;
        }
        if(flag)
        {
            printf(":(\n");
        }
        else
        {
            for(int i = 0; i < n; i ++)
            if(i)
                printf(" %d", a[i]);
            else
                printf("%d", a[i]);
            printf("\n");
        }
    }
}
