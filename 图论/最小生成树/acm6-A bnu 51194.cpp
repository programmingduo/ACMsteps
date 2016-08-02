#include<cstdio>
#include<algorithm>
using namespace std;

struct node
{
    int weight, in, pos;
    int begain, end;
}e[1000005];

int cmp1(node a, node b)
{
    if(a.weight == b.weight)
        return a.in > b. in;
    else
        return a.weight < b.weight;
}

int cmp2(node a, node b)
{
    return a.pos < b.pos;
}

int main ()
{
    int vertix, edge;
    while(~scanf("%d%d", &vertix, &edge))
    {
        for(int i = 0; i < edge; i ++)
        {
            scanf("%d%d", &e[i].weight, &e[i].in);
            e[i].pos = i;
        }
        sort(e, e + edge, cmp1);
        int last = 1, flag = 1;
        int l = 1, r = 2;
        for(int i = 0; i < edge; i ++)
        {
            if(e[i].in == 1)
            {
                last ++;
                e[i].begain = last - 1;
                e[i].end = last;
            }
            else
            {
                l ++;
                if(l >= r - 1)
                {
                    l = 1;
                    r ++;
                    if(r > last)
                    {
                        flag = 0;
                        break;
                    }
                    else
                    {
                        e[i].begain = l;
                        e[i].end = r;
                    }
                }
                else
                {
                    e[i].begain = l;
                    e[i].end = r;
                }
            }
        }
        if(!flag)
        {
            printf("-1\n");
            continue;
        }
        sort(e, e + edge, cmp2);
        for(int i = 0; i < edge; i ++)
        {
            printf("%d %d\n", e[i].begain, e[i].end);
        }
    }
    return 0;
}
