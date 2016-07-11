#include<cstdio>
#include<string.h>
#include<algorithm>

int prime[100005], primenum[100005];

int num[105];

int init()
{
    memset(prime, 0, sizeof(prime));
    int t = 0;
    prime[0] = prime[1] = 1;
    for(int i = 2; i < 100005; i ++)
    {
        if(!prime[i])
            primenum[t ++] = i;
        for(int j = 0; j < t && primenum[j] * i < 100005; j ++)
        {
            prime[i * primenum[j]] = 1;
            if(i % primenum[j] == 0)
                break;
        }
    }
//    for(int i = 0; i < t; i ++)
//    {
//        printf("%d ", primenum[i]);
//    }
//    printf("\n");
}

int max(int i, int j)
{
    return i > j ? i : j;
}

int dis(int i, int j)
{
    i = num[i], j = num[j];
    int temp = i;
    if(j < temp)
        temp = j;
    if(max(i - j, j - i) < temp)
        temp = max(i - j, j - i);
    return temp;
}

int connection(int i, int j)
{
    if(!prime[i] || !prime[j] || !prime[i + j])
        return 1;
    return 0;
}

int total, n, fa[105];
struct node
{
    int i, j, dis;
}edge[10005];

int cmp(node a, node b)
{
    return a.dis < b.dis;
}

int find(int i)
{
    if(fa[i] == i)
        return i;
    return fa[i] = find(fa[i]);
}

void merge(int a, int b)
{
    fa[fa[a]] = fa[b];
}

int tree()
{
    int totalDis = 0, cnt = 0;
    for(int i = 0; i <= n; i ++)
    {
        fa[i] = i;
    }
    std::sort(edge, edge + total, cmp);
    for(int i = 0; i < total; i ++)
    {
        if(find(edge[i].i) != find(edge[i].j))
        {
            merge(edge[i].i, edge[i].j);
            totalDis += edge[i].dis;
            cnt ++;
        }
    }
//    if(cnt != n - 1)
//        return -1;
    return totalDis;
}

int main ()
{
    init();
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        total = 0;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &num[i]);
            for(int j = 1; j < i; j ++)
            {
                if(connection(num[i], num[j]))
                {
                    edge[total].i = i;
                    edge[total].j = j;
                    edge[total].dis = dis(i, j);
                    total ++;
                }
            }
        }
        int ans = tree();
        printf("%d\n", ans);
    }
    return 0;
}
