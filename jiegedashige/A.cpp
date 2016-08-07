#include<cstdio>

int main ()
{
    int n, a, max = -0x3fffffff, min = 0x3fffffff,ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &a);
        if(a > max)
        {
            ans ++;
            max = a;
        }
        if(a < min)
        {
            ans ++;
            min = a;
        }
    }
    printf("%d\n", ans - 2);
    return 0;
}
