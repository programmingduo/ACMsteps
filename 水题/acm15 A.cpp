#include<cstdio>
#include<algorithm>

using namespace std;

struct node
{
    int a, b;
}total[105];

int cmp(node x, node y)
{
    return x.a > y.a;
}
int main ()
{
    int T;
    scanf("%d",&T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &total[i].a);
            total[i].b = i + 1;
        }
        sort(total, total + n, cmp);
        printf("%d %d\n", total[0].b, total[1].a);
    }
    return 0;
}
