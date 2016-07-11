#include<cstdio>

int b[500005], a[500005];
long long ans;
void merge(int l, int r, int mid)
{
//    int mid = (l + r) >> 1;
    int last = mid + 1, temp = l;
    while(l <= mid && last <= r)
    {
        if(a[l] <= a[last])
            b[temp ++] = a[l ++];
        else
        {
            ans += mid - l + 1;
            b[temp ++] = a[last ++];
        }
    }
    while(l <= mid)
        b[temp ++] = a[l ++];
    while(last <= r)
        b[temp ++] = a[last ++];
}

void mergesort(int l, int r)
{
    if(l >= r)
        return ;
    int mid = (l + r) >> 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
    for(int i = l; i <= r; i ++)
        a[i] = b[i];
}

int main ()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        ans = 0;
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        mergesort(0,n - 1);
//        for(int i = 0; i < n; i ++)
//            printf("%d ", a[i]);
//        printf("\n");

        printf("%lld\n", ans);
    }
    return 0;
}
