#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define maxm 10
#define maxl 10
#define maxn 26

#define mod 20090717
struct TNode
{
    int cnt,idx;
    TNode *fail;
    TNode *next[26];
    TNode()
    {
        cnt = 0;
        fail = NULL;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};
int dp[(1<<10)][maxn][maxl*maxm + 1];
class Trie
{
    private:
        TNode *root;
        TNode *queue[maxm * maxl + 1];
        int front,rear;
    public:
        void Init()
        {
            root = new TNode();
            return;
        }
        void Insert(const char *s,int val)
        {
            TNode *p = root;
            int len = strlen(s);
            for(int i = 0; i < len; i++)
            {
                if(p->next[s[i]-'a']==NULL)
                    p->next[s[i]-'a'] = new TNode();
                p = p->next[s[i]-'a'];
            }
            p->cnt = (1<<val);
        }
        void build_ac_automation()
        {
            front = rear = 0;
            root->fail = root;
            root->idx = rear;
            queue[rear++] = root;
            for(int i = 0; i < 26; i++)
            {
                if(root->next[i] != NULL)
                {
                    root->next[i]->fail = root;
                    root->next[i]->idx = rear;
                    queue[rear++] = root->next[i];
                }
            }
            front++;
            while(front < rear)
            {
                TNode *p = queue[front++];
                for(int i = 0; i < 26; i++)
                {
                    if(p->next[i] == NULL)
                        continue;
                    p->next[i]->idx = rear;
                    queue[rear++] = p->next[i];
                    TNode *q = p->fail;
                    while(q->next[i]==NULL && q!=root)
                        q = q->fail;
                    if(q->next[i]!=NULL)
                    {
                        p->next[i]->fail = q->next[i];
                        p->next[i]->cnt |= (q->next[i]->cnt);
                    }else
                    {
                        p->next[i]->fail = root;
                    }
                }
            }
        }
        int solve(int n,int m,int k)
        {
            memset(dp,0,sizeof(dp));
            dp[0][0][0] = 1;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < rear; j++)
                {
                    for(int ii = 0; ii < (1<<m); ii++)
                    {
                        if(dp[ii][i][j] == 0)
                            continue;
                        for(int jj = 0; jj < 26; jj++)
                        {
                            TNode *q = queue[j];
                            while(q->next[jj]==NULL && q!=root)
                                q = q->fail;
                            if(q->next[jj]!=NULL)
                                q = q->next[jj];
                            dp[ii|(q->cnt)][i+1][q->idx] = (dp[ii][i][j] + dp[ii|(q->cnt)][i+1][q->idx])%mod;
                        }
                    }
                }
            }
            int ans = 0;
            for(int i = 0; i < (1<<m) ; i++)
            {
                for(int j = 0; j < rear; j++)
                {
                    int tmp = 0;
                    int kk = i;
                    while(kk!=0)
                    {
                        tmp += (kk & 1);
                        kk = kk >> 1;
                    }
                    if(tmp >= k)
                    {
                        ans = (ans + dp[i][n][j])%mod;
                    }
                }
            }
            return ans;
        }
};
char str[maxl];
int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k))
    {
        if(n == 0 && m == 0 && k == 0)
            break;
        Trie trie;
        trie.Init();
        for(int i = 0; i < m; i++)
        {
            scanf("%s",str);
            trie.Insert(str,i);
        }
        trie.build_ac_automation();
        printf("%d\n",trie.solve(n,m,k));
    }
    return 0;
}
