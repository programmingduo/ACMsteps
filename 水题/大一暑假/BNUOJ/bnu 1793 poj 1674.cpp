#include<cstdio>

int main ()
{
    int T, num[10005];
    scanf("%d", &T);
    while(T --)
    {
        int n, ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &num[i]);
        for(int i = 1; i <= n; i ++)
        {
            if(num[i] == i)
                continue ;
            int first = num[i], last = i;
            num[i] = i;
            while(1)
            {
                ans ++;
                if(num[first] == i)
                {
                    num[first] = first;
                    break;
                }
                last = first;
                first = num[first];
                num[last] = last;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
