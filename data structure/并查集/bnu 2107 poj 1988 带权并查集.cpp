#include<cstdio>

#define maxn 300005
int fa[maxn], cnt[maxn], dis[maxn];

void init(int n)
{
    for(int i = 0; i <= n; i ++)
        fa[i] = i, dis[i] = 0, cnt[i] = 1;
}

int findf(int son)
{
    if(fa[son] == son)
        return son;
    int temp = findf(fa[son]);
    dis[son] += dis[fa[son]];
    return fa[son] = temp;
}

void unionatob(int a, int b)
{
    int fofa = findf(a);
    int fofb = findf(b);
    if(a == b)
        return ;
    fa[fofa] = fofb;
    dis[fofa] += cnt[fofb];
    cnt[fofb] += cnt[fofa];
}

int main ()
{
    int T, a, b;
    char c;
    while(~scanf("%d", &T))
    {
        init(T);
        while(T --)
        {
            getchar();
            scanf("%c", &c);
            switch(c)
            {
            case 'M':
                scanf("%d%d", &a, &b);
                unionatob(a, b);
                break;
            case 'C':
                scanf("%d", &a);
                findf(a);
                printf("%d\n", dis[a]);
                break;
            }
        }
    }
    return 0;
}
