#include<cstdio>

int a[1005], ans[1005];

int main()
{
    int n, p = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    ans[0] = 1;
    for(int i = 1; i < n; i ++)
    {
        ans[i] = 1;
        for(int j = i - 1; j >= 0; j --)
            if(a[i] > a[j])
            ans[i] = ans[i] > ans[j] + 1 ? ans[i] : ans[j] + 1;
        if(ans[i] > p)
            p = ans[i];
    }
    printf("%d\n", p);
    return 0;
}
