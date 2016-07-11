#include<cstdio>
#include<string.h>

int ans[13000];

int main()
{
    int N, M, a, b;
    scanf("%d%d", &N, &M);
    memset(ans, 0, sizeof(ans));
    for(int j = 0; j < N; j ++)
    {
        scanf("%d%d", &a, &b);
        for(int i = M; i > 0; i --)
        {
            if(i < a)
                break;
            ans[i] = ans[i] > ans[i - a] + b? ans[i] : ans[i - a] + b;
        }
    }
    printf("%d\n", ans[M]);
    return 0;
}
