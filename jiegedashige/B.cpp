#include<cstdio>
#include<algorithm>

struct node
{
    int x, y;
}a[1005];

int cmp(node x, node y)
{
    if(x.y == y.y)
        return x.x > y.x;
    return x.y > y.y;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    std::sort(a, a + n, cmp);
    int op = 1;
    long long ans = 0;
    for(int i = 0; i < n && op; i ++)
    {
        op --;
        op += a[i].y;
        ans += a[i].x;
    }
    printf("%lld\n", ans);
    return 0;
}
