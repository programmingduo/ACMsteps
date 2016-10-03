#include<cstdio>
#include<string.h>

struct node{
    node * next[3];
    int val;
    void clean()
    {
        val = 0;
        memset(next, 0, sizeof(next));
    }
}*root;

void release(node *p)
{
    for(int i = 0; i < 3; i ++)
    {
        if(p->next[i] != NULL)
            release(p->next[i]);
    }
    delete p;
}

void insert(char *s)
{
    node *p = root;
    int len = strlen(s);
    for(int i =0 ;i < len ; i ++)
    {
        int t = s[i] - 'a';
        if(p->next[t] == 0)
        {
             p->next[t] = new node;
             p->next[t]->clean();
        }
        p = p->next[t];

    }
    p->val = 1;
}

//flag = 0: no change
bool search(char *s, int flag, node *p)
{
    if(strlen(s) == 0)
        return flag;
    int t= s[0] - 'a';
    if(flag)
    {
        if(p->next[t] == NULL)
            return 0;
        return search(s + 1, 1, p->next[t]);
    }
    else
    {
        if(p->next[t] != NULL)
            if(search(s + 1, 0, p->next[t]))
            return 1;
        t = (t + 1) % 3;
        if(p->next[t] != NULL)
            if(search(s + 1, 1, p->next[t]))
            return 1;
        t = (t + 1) %3;
        if(p->next[t] != NULL)
            if(search(s + 1, 1, p->next[t]))
            return 1;
        return 0;
    }
}

char c[1000000];

int main ()
{
    int n ,m;

    while(~scanf("%d%d", &n, &m))
    {
        root = new node;
        root ->clean();
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", c);
            insert(c);
        }

        for(int i = 0; i < m; i ++)
        {
            scanf("%s", c);
            if(search(c, 0, root))
                printf("YES\n");
            else
                printf("NO\n");
        }
        release(root);
    }
}


/*
#include<cstdio>
#include<string>
#include<iostream>
#include<map>

using namespace std;

map<string, int> ma;

int main ()
{
    int n, m;
    string s;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; i ++)
        {
            cin>> s;
            ma[s] = 1;
        }
        char temp;
        for(int i = 0; i < m; i ++)
        {
            cin>> s;
            int flag = 0;
            for(int j = 0; j < s.length();j ++)
            {
                temp = s[j];
                if(temp != 'a')
                {
                    s[j] = 'a';
                    if(ma[s] == 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(temp != 'b')
                {
                    s[j] = 'b';
                    if(ma[s] == 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(temp != 'c')
                {
                    s[j] = 'c';
                    if(ma[s] == 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                s[j] = temp;
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
*/
