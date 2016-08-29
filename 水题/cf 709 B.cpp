#include<cstdio>
#include<algorithm>

int a[100005];
int abs(int x)
{
    if(x < 0)
        return -x;
    return x;
}
int min(int x, int y)
{
    return x< y? x: y;
}

int main ()
{
    int n, s;
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    if(n == 1)
    {
        printf("0\n");
        return 0;
    }

    int l1 = s - a[1];
    int l0 = s - a[0];
    int r1 = s - a[n - 2];
    int r0 = s - a[n - 1];
    if(n == 2)
    {
        printf("%d\n", min(abs(l1), abs(l0)));
        return 0;
    }
    int ans;
    if(l0 <= 0)
    {
        ans = -r1;
    }
    else if(l1 < 0 && l0 > 0)
    {
        ans = min(-r0, min(l0, -r1) + l0 - r1);
    }
    else if(r0 >= 0)
    {
        ans = l1;
    }
    else if(r0 < 0 && r1 > 0)
    {
        ans = min(l0, min(l1, -r0) + l1 - r0);
    }
    else
    {
        ans = min(l0 - r1 + min(l0, -r1), l1 - r0 + min(l1, -r0));
    }
    printf("%d\n", ans);
    return 0;
}
