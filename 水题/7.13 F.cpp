#include<cstdio>

int a[105];

int main ()
{
    int n, pos;
    while(~scanf("%d%d", &n, &pos))
    {
        pos --;
        int ans = 0, l, r;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i < n; i ++)
        {
            l = pos - i;
            r = pos + i;
            if(l >= 0 && r < n)
            {
                if(a[l] && a[r])
                    ans += 2;
            }
            else
            {
                if(r < n)
                    ans += a[r];
                else if(l >= 0)
                    ans += a[l];
            }
        }
        ans += a[pos];
        printf("%d\n", ans);
    }
    return 0;
}
