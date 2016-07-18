#include<cstdio>

int a[100005], b[100005];

int main ()
{
    int N;
    long long ans;
    while(~scanf("%d", &N))
    {
        if(N == 0)
        {
            printf("1\n");
            continue;
        }
        ans = 0;
        int height = 0;
        for(int i = 0; i < N; i ++)
        {
            scanf("%d%d", &a[i], &b[i]);
            if(a[i] > height)
                height = a[i];
        }
        height ++;
        for(int i = 0; i < N; i ++)
        {
            ans += (height - a[i]) * b[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
