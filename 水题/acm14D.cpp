#include<cstdio>

int num[10004];
long long pre[10004], total;

int main ()
{
    int N;
    long long a, b;
    while(~scanf("%d", &N))
    {
        int flag = 1;
        total = 0;
        for(int i = 0; i < N; i ++)
        {
            scanf("%lld%lld", &a, &b);
            num[i] = a - b;
            total += num[i];
            pre[i] = total;
        }
        if(total % 2 == 1)
            flag = 0;
        for(int i = 0; i < N && flag; i ++)
        {
            if(num[i] > total - num[i])
                flag = 0;
        }
        if(!flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
