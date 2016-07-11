#include<cstdio>
#include<string.h>

struct node
{
    int id, flag;
    node* next[27];

    node()
    {
        id = -1;
        flag = 0;
        memset(next, 0, sizeof(next));
    }
}root;

int degree[500005], color;
int fa[500005];
int find(int a)
{
    if(fa[a] == a)
        return a;
    return fa[a] = find(fa[a]);
}

void merge(int a, int b)
{
    int af = find(a), bf = find(b);
    if(af != bf)
        fa[af] = bf;
}

int get_id(char a[])
{
    node* p = &root;
    int i, index;
    for(i = 0; a[i] != '\0'; i ++)
    {
        index = a[i] - 'a';
        if(p->next[index] == 0)
            p->next[index] = new node;
        p = p->next[index];
    }

    if(p->flag)
        return p->id;
    else
    {
        p->flag = 1;
        p->id = color ++;
        return p->id;
    }
}

int main ()
{
    for(int i = 0; i < 500005; i ++)
        fa[i] = i;
    memset(degree, 0, sizeof(degree));
    color = 0;
    char a[15], b[16];
    while(~scanf("%s%s", a, b))
    {
        int i = get_id(a), j = get_id(b);
        degree[i] ++;
        degree[j] ++;
        merge(i, j);
    }

    int f = find(0), t = 0;
    for(int i = 1; i < color; i ++)
    {
        t = find(i);
        if(t != f)
        {
            printf("Impossible\n");
            return 0;
        }
    }

    int num = 0;
    for(int i = 0; i < color; i ++)
    {
        if(degree[i] %2 == 1)
            num ++;
        if(num > 2)
        {
            printf("Impossible\n");
            return 0;
        }
    }

    if(num == 1)
        printf("Impossible\n");
    else
        printf("Possible\n");

    return 0;
}
