#include<cstdio>
#include<algorithm>

struct node
{
    int co, po,aim;
}a[1005], b[1005];

int cmp1(node x, node y)
{
    if(x.co == y.co)
        return x.po < y.po;
    return x.co < y.co;
}
int cmp2(node x, node y)
{
    return x.aim<y.aim;
}
int cmp3(node x, node y)
{
    return x.po < y.po;
}

int main ()
{
    int T, n, m;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i].co);
            a[i].po = i;
        }
        for(int j = 0; j < n; j ++)
        {
            scanf("%d", &b[j].co);
            b[j].po = j;
        }
        std::sort(a, a + n, cmp1);
        std::sort(b, b + n, cmp1);

        int flag = 1;
        for(int i = 0; i < n; i ++)
        {
            if(a[i].co != b[i].co)
            {
                flag = 0;
                break;
            }
            a[i].aim = b[i].po;
        }
//        for(int i =0; i < n; i ++)
//        {
//            printf("%d %d\n", a[i].aim, a[i].co);
//        }
        std::sort(a, a + n, cmp3);
        int l, r;
        while(m --)
        {
            scanf("%d %d", &l, &r);
            if(flag)
            {
                std::sort(a + l - 1, a + r, cmp2);
//                for(int i = l - 1; i < r; i ++)
//                {
//                    printf("%d %d\n", a[i].co, a[i].aim);
//                }
            }
        }
        if(flag)
        {
            for(int i = 0; i < n; i ++)
            {
                if(a[i].aim != i)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
}
