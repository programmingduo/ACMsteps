#include<cstdio>
#include<string.h>

int ans[250005], v[5005];

int main ()
{
    int N;
    while(scanf("%d", &N) && N > 0)
    {
        int a, b, total = 0, totalvalue = 0;
        for(int i = 0; i < N; i ++)
        {
            scanf("%d%d", &a, &b);
            for(int j = 0; j < b; j ++)
            {
                v[total ++] = a;
                totalvalue += a;
            }
        }
        int value = totalvalue / 2;

        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < total; i ++)
        {
            for(int j = value; j >= 0; j --)
            {
                if(j < v[i])
                    break;
                ans[j] = ans[j] > ans[j - v[i]] + v[i] ? ans[j] : ans[j - v[i]] + v[i];
            }
        }
        int p = ans[value] > totalvalue - ans[value]? ans[value] : totalvalue - ans[value];
        printf("%d %d\n", p, totalvalue - p);

    }
    return 0;
}
