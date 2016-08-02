#include<cstdio>
#include<algorithm>
#include<iostream>

struct node
{
    char color[100];
    int q;
}a[100];

bool cmp(node a, node b)
{
    return a.q > b.q;
}

int main ()
{
    int n, total;
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d", &total);
        for(int i = 0; i < total; i ++)
        {
            std::cin>> a[i].color>> a[i].q;
        }

        std::sort(a, a + total, cmp);
        for(int i = 0; i < total; i ++)
        {
            if(i)
                printf(" %s", a[i].color);
            else
                printf("%s", a[i].color);
        }
        printf("\n");
    }
    return 0;
}
