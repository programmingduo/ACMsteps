#include<cstdio>

int main()
{
    int a = 24, mod, b;
    scanf("%d", &mod);
    while(~scanf("%d %d", &a, &b) && a)
    {
        int ans = 1;
        int temp = a;
        if(b == 0)
        {
            printf("0\n");
        }
        while(a % mod != b)
        {
            a = a * temp % mod;
            ans ++;
            if(a == temp || a == 0)
            {
                ans = 0;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
