#include<cstdio>
#include<algorithm>

struct Node
{
    int x, id;
}node[100005];

int cmp(Node a, Node b)
{
    return a.x < b.x;
}

int main ()
{
    int n, t, a, b, c;
    scanf("%d%d", &n, &t);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &a);
        node[i].id = i;
        node[i].x = a;
    }
    std::sort(node, node + n, cmp);
    for(int i = 0; i < t; i ++)
    {
        scanf("%d %d %d", &a, &b, &c);
        for(int j = 0; j < n; j ++)
        {
            if(node[j].id >= a - 1 && node[j].id <= b - 1)
                c --;
            if(c == 0)
            {
                printf("%d\n", node[j].x);
                break;
            }
        }
    }
    return 0;
}
