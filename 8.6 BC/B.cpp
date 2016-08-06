#include<cstdio>
int a[100004];

int abs(int t)
{
    if(t < 0)
        return -t;
    return t;
}

int max(int x, int y)
{
    return x>y? x: y;
}

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        int max1 = 0, max2 = 0, max3 = 0;
        long long total = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            if(i)
            {
                int temp = abs(a[i] - a[i - 1]);
                if(temp > max1)
                {
                    max3 = max2;
                    max2 = max1;
                    max1 = temp;
                }
                else if(max2 < temp)
                {
                    max3 = max2;
                    max2 = temp;
                }
                else if(max3 < temp)
                    max3 = temp;
            }
        }
        for(int i = 0; i < n - 2; i ++)
        {
//            printf("%d %d %d\n", a[i], a[i + 2], abs(a[i] - a[i + 2]));
            int temp = abs(a[i] - a[i + 2]);
//            printf("%d %d %d\n", a[i], a[i + 2], temp);
            int temp1 = abs(a[i] - a[i + 1]), temp2 = abs(a[i + 1] - a[i + 2]);
            if(temp1 == max1 && temp2 == max2 || temp1 == max2 && temp2 == max1)
            {
                if(temp > max3)
                    total += temp;
                else
                    total += max3;
            }
            else if(temp1 == max1 || temp2 == max1)
            {
                if(temp > max2)
                    total += temp;
                else
                    total += max2;
            }
            else
                total += max(temp, max1);
//            printf("%lld\n", total);
//            printf("%I64d ", total);
        }
        int temp = abs(a[0] - a[1]);
        if(temp == max1)
            total += max2;
        else
            total += max1;
        temp = abs(a[n - 1] - a[n - 2]);
        if(temp == max1)
            total += max2;
        else
            total += max1;
        printf("%I64d\n", total);
    }
}
