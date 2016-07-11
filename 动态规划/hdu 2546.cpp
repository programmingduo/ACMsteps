#include<cstdio>
#include<string.h>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int a[1005], ans[1005];
int main()
{
    int N, m;
    while(~scanf("%d", &N) && N)
    {
        int max = (int)0x80000001;
        int id = 0;
        for(int i = 0; i < N; i ++)
        {
            scanf("%d", &a[i]);
            if(a[i] > max)
                max = a[i], id = i;
        }
        scanf("%d", &m);
        if(m < 5)
        {
            printf("%d\n", m);
            continue;
        }
        memset(ans, 0, sizeof(ans));
        swap(a[id], a[N - 1]);
        N --;
        m -= 5;
        for(int i = 0; i < N; i ++)
        {
            for(int j = m; j > 0; j --)
            {
                if(j < a[i])
                    break;
                ans[j] = ans[j] > ans[j - a[i]] + a[i] ? ans[j] : ans[j - a[i]] + a[i];
            }
        }
        printf("%d\n", m - ans[m] - a[N] + 5);
    }
    return 0;
}
