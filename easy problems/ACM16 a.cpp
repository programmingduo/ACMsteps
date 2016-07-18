#include<cstdio>

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int a, b, ans = 0;
        scanf("%d%d", &a, &b);
        while(a != 0 && b != 0)
        {
            if(a < b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            ans += a / b;
            a = a % b;
        }
        printf("%d\n", ans);

    }
    return 0;
}
