#include<cstdio>

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int x = 1, y = 1, ans = 1;
        while(!((x + y) % n == 1 && (x + y * 2) % n == 1))
        {
            ans ++;
            x = (x + y) % n;
            y = (x + y) % n;
        }
        printf("%d\n", ans);
    }
    return 0;
}
