#include<cstdio>
#include<string.h>

char c[100005];

struct node {
    node *next[26];

    node()
    {
        for(int i = 0; i < 26; i ++)
            next[i] = NULL;
    }
}*root;

int insert(char *a)
{
    int ret = 0, t, flag = 1;
    node *p = root;
    for(int i = 0; a[i]; i ++)
    {
        t = a[i] - 'a';
        if(p->next[t] == 0)
        {
            if(flag)
            {
                ret = i;
                flag = 0;
                //printf("%d %c\n", i, a[i]);
            }
            p->next[t] = new node();
        }
        p = p->next[t];
    }
    if(flag)
        return strlen(a);
    return ret + 1;
}

int main ()
{
    int T, n, ans;
    scanf("%d", &T);
    for(int i = 1; i <= T; i ++)
    {
        ans  = 0;
        root = new node();
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", c);
            ans += insert(c);
        }
        printf("Case #%d: %d\n", i, ans);
    }
}
