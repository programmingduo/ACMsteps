#include<cstdio>

using namespace std;

const int maxn = 2005;
bool mark = 1;
int bugs, father[maxn * 2 + 5];

void merge(int, int);
void init(int);
int find(int);

int main ()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i ++)
    {
        mark = 1;
        int relations;
        scanf("%d%d", &bugs, &relations);
        init(bugs);
        int a, b;
        for(int j = 0; j < relations; j ++)
        {
            scanf("%d%d", &a, &b);
            if(a == b)
                continue;
            if(mark)
            {
                merge(a, b + bugs);
                merge(b, a + bugs);
            }
        }
        printf("Scenario #%d:\n", i);
        if(mark)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");

    }
}

void merge(int a, int b)
{
    int fa, fb;
    fa = find(a);
    fb = find(b - bugs);

    if(fa == fb)
    {
        mark = 0;
        return ;
    }

    fb = find(b);
    father[fa] = fb;
}

int find(int a)
{
    if(father[a] != a)
        father[a] = find(father[a]);

    return father[a];
}

void init(int bugs)
{
    for(int i = 1; i <= bugs; i ++)
    {
        father[i] = i;
        father[i + bugs] = i + bugs;
    }
}
