#include<cstdio>

int a[100005], nex[100005];

int main ()
{
    int T, n, q;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
        }

        nex[n] = n + 1;
        for(int i = n - 1; i > 0; i --)
        {
            int temp = i + 1;
            while(temp < n)
            {
                if(a[temp] < a[i])
                {
                    break;
                }
                else
                {
                    temp = nex[temp];
                }
            }
            nex[i] = temp;
        }

        scanf("%d", &q);
        while(q --)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            int ans = a[l];
            while(nex[l] <= r)
            {
                ans %= a[nex[l]];
                l = nex[l];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
