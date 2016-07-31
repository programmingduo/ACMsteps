#include<cstdio>
#include<algorithm>

int a[100006];

int main ()
{
    int T, n, k;
    scanf("%d", &T);
    while(T --)
    {
        long long sum = 0;
        scanf("%d %d", &n, &k);
        for(int i = 0;  i < n - 1; i ++)
        {
            scanf("%d", &a[i]);
            a[i] ++;
        }
        if(k >= n)
        {
            printf("%d\n", n);
            continue;
        }
        std::sort(a, a+n - 1);
        n -= k;
        for(int i = 0; i < n; i ++)
        {
            sum += a[i];
        }
        sum += k;
        printf("%I64d\n", sum);
    }
    return 0;
}
