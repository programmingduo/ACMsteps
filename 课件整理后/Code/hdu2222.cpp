#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
#define maxn 500000
struct TNode
{
    TNode* fail;
    TNode* next[26];
    int cnt;
    TNode()
    {
        cnt = 0;
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        fail = NULL;
        return;
    }
};
TNode *root;
void Insert(const char *s)
{
    int len = strlen(s);
    TNode *p = root;
    for(int i = 0; i < len; i++)
    {
        if( p->next[s[i]-'a'] == NULL )
        {
            p->next[s[i]-'a'] = new TNode();
        }
        p = p->next[s[i]-'a'];
    }
    p->cnt++;
    return;
}
TNode* queue[maxn];
void build_ac_automation()
{
    int front,rear;
    front = rear = 0;
    root->fail = root;
    for(int i = 0; i < 26; i++)
    {
        if(root->next[i] != NULL)
        {
            root->next[i]->fail = root;
            queue[rear++] = root->next[i];
        }
    }
    while(front < rear)
    {
        TNode *p = queue[front++];
        for(int i = 0; i < 26; i++)
        {
            TNode *q = p->fail;
            if(p->next[i]==NULL)
                continue;
            queue[rear++] = p->next[i];
            while(q->next[i]==NULL&&q!=root)
                q = q->fail;
            if(q->next[i] == NULL)
                p->next[i]->fail = root;
            else
                p->next[i]->fail = q->next[i];
        }
    }
    return;
}
int Query(const char* s)
{
    int len = strlen(s);
    TNode *p = root;
    int ans = 0;
    for(int i = 0; i < len; i++)
    {
        while(p->next[s[i]-'a'] == NULL && p!=root)
            p = p->fail;
        if(p->next[s[i]-'a'] != NULL)
        {
            p = p->next[s[i]-'a'];
        }
        TNode *q = p;
        while(q!=root)
        {
            ans += q->cnt;
            q->cnt = 0;
            q = q -> fail;
        }
    }
    return ans;
}
char s[55];
char str[1000010];
int main()
{

    int T,n;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            root = new TNode();
            scanf("%d",&n);
            for(int i = 0; i < n; i++)
            {
                scanf("%s",s);
                Insert(s);
            }
            build_ac_automation();
            scanf("%s",str);
            int ans = Query(str);
            printf("%d\n",ans);
        }
    }
    return 0;
}
