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

bool search(char *s)
{
    node *p = root;
    int len = strlen(s);
    for(int i = 0; i < len; i ++)
    {
        int t = s[i] - 'a';
        if(p->next[t] == 0)
            return false;
        p = p->next[t];
    }
    return p->val;
}

char c[100000];

int main ()
{
    int n ,m;
    root = new node;
    root->clean();
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", c);
            insert(c);
        }

        char temp;
        for(int i = 0; i < m; i ++)
        {
            scanf("%s", c);
            int flag = 0, len = strlen(c);
            for(int j = 0; j < len;j ++)
            {
                temp = c[j];
                if(temp != 'a')
                {
                    c[j] = 'a';
                    if(search(c))
                    {
                        flag = 1;
                        break;
                    }
                }
                if(temp != 'b')
                {
                    c[j] = 'b';
                    if(search(c))
                    {
                        flag = 1;
                        break;
                    }
                }
                if(temp != 'c')
                {
                    c[j] = 'c';
                    if(search(c))
                    {
                        flag = 1;
                        break;
                    }
                }
                c[j] = temp;
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
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
