#include<cstdio>
#include<algorithm>
int a[1000005];

int main ()
{
    int n, k;
    while(~scanf("%d %d", &n, &k))
    {
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        std::sort(a, a + n);
        printf("%d\n", a[n - k]);
    }
    return 0;
}
