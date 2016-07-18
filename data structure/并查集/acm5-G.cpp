#include<cstdio>
#include<string.h>

int father[1000005], ans[100005];

void init(int n)
{
    for(int i = 0; i < n + 4; i ++)
        father[i] = i;
}

int find(int a)
{
    if(father[a] == a)
        return a;

    father[a] = find(father[a]);
    return father[a];
}

void merge(int a, int b)
{
    int tempa = find(a);
    int tempb = find(b);
    father[father[b]] = tempa;
}

int main ()
{
    int T, print, n, a, b, v ;
    scanf("%d", &T);
    while(T --)
    {
        memset(ans, 0, sizeof(ans));
        print = 0;
        scanf("%d", &n);
        init(n);
        for(int i = 0; i < n - 1; i ++)
        {
            scanf("%d%d%d", &a, &b, &v);
            if(v == 0)
                merge(a, b);
        }
        for(int i = 1; i <= n; i ++)
        {
            ans[find(i)] ++;
        }
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", ans[i]);
        for(int i = 1; i <= n; i ++)
            if(ans[i] % 2 == 1)
            print = print ^ ans[i];
        printf("%d\n", print);
    }
    return 0;
}
