#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define maxn 100010
char virus[210];
char webstr[10010];
struct TNode
{
        int cnt;
        TNode *fail;
        TNode *next[100];
        TNode()
        {
            cnt = -1;
            fail = NULL;
            for(int i = 0; i < 100; i++)
                next[i] = NULL;
        }
};
class Trie
{
    private:
        TNode *root;
        TNode *queue[maxn];
    public:
        Trie()
        {
            root = new TNode();
        }
        void Insert(const char *str,int val)
        {
            TNode *p = root;
            int len = strlen(str);
            for(int i = 0; i < len; i++)
            {
                if(p->next[str[i]-32] == NULL)
                {
                    p->next[str[i]-32] = new TNode();
                }
                p = p->next[str[i]-32];
            }
            p->cnt = val;
        }
        void build_ac_automation()
        {
            root->fail = root;
            int front,rear;
            front = rear = 0;
            for(int i = 0; i < 100; i++)
            {
                if(root->next[i]!=NULL)
                {
                    root->next[i]->fail = root;
                    queue[rear++] = root->next[i];
                }
            }
            while(front < rear)
            {
                TNode *p = queue[front++];
                for(int i = 0; i < 100; i++)
                {
                    TNode *q = p->fail;
                    if(p->next[i] == NULL)
                        continue;
                    queue[rear++] = p->next[i];
                    while(q->next[i]==NULL && q!=root)
                        q = q->fail;
                    if(q->next[i] == NULL)
                        p->next[i]->fail = root;
                    else
                        p->next[i]->fail = q->next[i];
                }
            }
            return;
        }
        int Query(const char * s,int n,int id)
        {
            int ans[502];
            int flag = 0;
            memset(ans,0,sizeof(ans));
            TNode *p = root;
            int len = strlen(s);
            for(int i = 0; i < len; i++)
            {
                while( p->next[s[i]-32] == NULL && p != root)
                    p = p->fail;
                if( p->next[s[i]-32] != NULL)
                    p = p->next[s[i]-32];
                TNode *q = p;
                while(q!=root)
                {
                    if(q->cnt!=-1){
                        ans[q->cnt] = 1;
                        flag = 1;
                    }
                    q = q->fail;
                }
            }
            if(flag)
            {
                printf("web %d:",id);
                for(int i = 0; i < n; i++)
                {
                    if(ans[i])
                        printf(" %d",i+1);
                }
                printf("\n");
            }
            return flag;
        }
};
int main()
{
    int n,m,ans;
    while(scanf("%d",&n)!=EOF)
    {
        Trie trie = Trie();
        ans = 0;
        gets(virus);
        for(int i = 0; i < n; i++)
        {
            gets(virus);
            //scanf("%s",virus);
            trie.Insert(virus,i);
        }
        trie.build_ac_automation();
        scanf("%d",&m);
        gets(webstr);
        for(int i = 0; i < m; i++)
        {
            gets(webstr);
            ans += trie.Query(webstr,n,i+1);
        }
        printf("total: %d\n",ans);
    }
    return 0;
}
