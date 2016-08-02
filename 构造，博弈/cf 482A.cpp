#include<cstdio>
#include<algorithm>

int a[100005];

int main ()
{
    int n, k;
    while(~scanf("%d %d", &n, &k))
    {
        int flag = k, num = 1, t = 0;
        flag --;
        for(int i = 0; i < n; i ++)
        {
            if(flag > 1)
            {
                a[i ++] = num ++;
                a[i] = n - t;
                t ++;
                flag -= 2;
            }
            else
            {
                a[i] = num ++;
            }
        }
        if(flag)
            std::swap(a[n - 1], a[n - 2]);
        for(int i = 0; i < n; i ++)
        {
            if(i)
                printf(" %d", a[i]);
            else
                printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
