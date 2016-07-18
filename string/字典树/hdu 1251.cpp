#include<cstdio>
#include<string.h>
//G++  MLE  C++ AC

struct node
{
    int id;
    node *next[26];

    node()
    {
        id = 0;
        for(int i = 0; i < 26; i ++)
            next[i] = NULL;
    }
};

node *p, *root = new node();

void insert(char *a)
{
    p = root;
    int t;
    for(int i = 0; a[i]; i ++)
    {
//        printf("%c", a[i]);
        t = a[i] - 'a';
        if(p->next[t] == NULL)
            p->next[t] = new node();

        p = p->next[t];
        p->id ++;
    }
}

int search(char *a)
{
    p = root;
    int len = strlen(a), t;
    for(int i = 0; i < len; i ++)
    {
        t = a[i] - 'a';
        if(p->next[t] == 0)
            return 0;
        p = p->next[t];
    }
    return p->id;
}

int main ()
{
    char s[11];
    while(gets(s), *s)
        insert(s);
    while(gets(s))
        printf("%d\n", search(s));

    return 0;
}
