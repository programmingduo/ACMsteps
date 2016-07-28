#include<cstdio>
#include<algorithm>

struct node
{
    int num, pos;
}no[10000005];

int cmp(node a, node b)
{
    return a.num<b.num;
}

int main ()
{
    int n, t;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &t);
        no[i].num = t;
        no[i].pos = i;
    }

    std::sort(no+1, no+n+1, cmp);
    for(int i = 1; i<= n/2; i ++)
    {
        printf("%d %d\n", no[i].pos, no[n+1-i].pos);
    }

    return 0;

}
