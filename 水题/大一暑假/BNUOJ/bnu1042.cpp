#include<cstdio>

int main ()
{
    int i;
    scanf("%d", &i);
    while(i --)
    {
        int n, ans = 1;
        scanf("%d", &n);
        for(int j = 0; j < n; j ++)
            ans *= 8;
        printf("%d\n", ans);
    }
    return 0;
}
