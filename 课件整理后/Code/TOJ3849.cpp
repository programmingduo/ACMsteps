#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
#define maxn 100
#define maxq 500000
#define maxl 20000
struct TNode
{
    TNode* fail;
    TNode* next[26];
    int cnt,len;
    TNode()
    {
        fail = NULL;
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        cnt = -1;
        len = -1;
    }
    void print()
    {
        printf("%d %d\n",cnt,fail);
    }
};
int dp[maxl+1];
class Trie
{
    private:
        TNode* root;
        TNode* queue[maxq];
    public:
        void Init()
        {
            root = new TNode();
        }
        void Insert(const char* s, int val)
        {
            TNode *p = root;
            int len = strlen(s);
            for(int i = 0; i < len; i++)
            {
                if(p->next[s[i]-'a'] == NULL)
                    p->next[s[i]-'a'] = new TNode();
                p = p->next[s[i]-'a'];
            }
            p->cnt = val;
            p->len = len;
        }
        void build_ac_automata()
        {
            int front,rear;
            root->fail = root;
            front = rear = 0;
            for(int i = 0; i < 26; i++)
            {
                if(root->next[i]!=NULL)
                {
                    queue[rear++] = root->next[i];
                    root->next[i]->fail = root;
                }
            }
            while(front < rear)
            {
                TNode *p = queue[front++];
                for(int i = 0; i < 26; i++)
                {
                    if(p->next[i] == NULL)
                        continue;
                    TNode *q = p->fail;
                    queue[rear++] = p->next[i];
                    while(q->next[i]==NULL && q != root)
                         q = q->fail;
                    if(q->next[i]!=NULL)
                        p->next[i]->fail = q->next[i];
                    else
                        p->next[i]->fail = root;
                }
            }
        }
        void solve(const char *str)
        {
            int dir = 0;

            int len = strlen(str);
            memset(dp,-1,sizeof(dp));
            dp[0] = 0;
            TNode *p = root;
            for(int i = 0; i < len; i++)
            {
               // printf("%d\n",i);
                while(p->next[str[i]-'a'] == NULL && p != root)
                    p = p->fail;
                if(p->next[str[i]-'a'] != NULL)
                    p = p->next[str[i] - 'a'];
                TNode *q = p;
                while(q!=root)
                {
                    if(q->cnt!=-1 && dp[i+1-q->len] != -1)
                    {
                        dp[i+1] = dp[i+1-q->len] + q->cnt > dp[i+1] ? dp[i+1-q->len] + q->cnt : dp[i+1];
                    }
                    q = q->fail;
                }
            }
            printf("%d\n",dp[len]);
        }
};
int main()
{
    char str[maxn];
    char strl[maxl];
    int n,val;
    while(scanf("%d",&n)!=EOF)
    {
        Trie trie;
        trie.Init();
        for(int i = 0; i < n; i++)
        {
            scanf("%s%d",str,&val);
            trie.Insert(str,val);
        }
        trie.build_ac_automata();
        //system("pause");
        scanf("%s",strl);
        trie.solve(strl);
    }
    return 0;
}
