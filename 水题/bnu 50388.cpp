#include<cstdio>
#include<algorithm>
int a[1000005];
int main ()
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        a[n ++] = m;
        std::sort(a, a + n);
        for(int i = 0; i < n; i ++)
        {
            if(a[i] == m)
                printf("%d\n", i + 1);
        }
    }
    return 0;
}
