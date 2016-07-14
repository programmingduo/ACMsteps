#include<cstdio>
#include<string.h>

char s[60];

int max(int a, int b)
{
    return a> b? a: b;
}

int getIndex(char c)
{
    switch(c)
    {
    case 'A':
        return 0;
    case 'G':
        return 1;
    case 'C':
        return 2;
    case 'T':
        return 3;
    }
}

struct node
{
    int val, pos;
    node *next[4];

    void clean()
    {
        val = pos = 0;
        memset(next, 0, sizeof(next));
    }
}*root;

void insert(char * c)
{
    node *p = root;
    int len = strlen(c);
    int t;
    for(int i = 0; i < len; i ++)
    {
        t = getIndex(c[i]);
        if(p->next[t] == NULL)
        {
            p->next[t] = new node();
            p->next[t]->clean();
        }
        p = p->next[t];
        p->val ++;
        p->pos = i + 1;
    }
}

int search(node *p)
{
    if(p == NULL)
        return 0;
    int t = p->val * p->pos;
    for(int i = 0; i < 4; i ++)
    {
        t = max(t, search(p->next[i]));
    }
    return t;
}

int main ()
{
    int T, n;
    root = new node();
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        root->clean();
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", s);
            insert(s);
        }
        int ans = search(root);
        printf("Case %d: %d\n", t, ans);
    }
}
