#include<string.h>
#include<cstdio>

unsigned long long ans[55];

void init()
{
    memset(ans, 0, sizeof(ans));
    ans[1] = 3;
    ans[2] = 6;
    ans[3] = 6;
    for(int i = 4; i < 52; i ++)
    {
        ans[i] = ans[i - 1] + ans[i - 2] * 2;
    }
}

int main()
{
    int a;
    init();
    while(~scanf("%d", &a))
    {
        printf("%I64u\n", ans[a]);
    }
    return 0;
}
