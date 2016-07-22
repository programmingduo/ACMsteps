#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

struct node
{
    node *s[26], *fail;
    char c;
    int w;
}*head;
struct
{
    int x, y, len;
    char c;
}outdata[2001];
char s[1001][1010], str[20000];
int face, r, c;
int t[8][2]={{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
queue<node*> q;

node *updateFail(node *p, int k)
{
    if(p->s[k] != NULL)
        return p->s[k];
    if(p == head)
        return head;
    return updateFail(p->fail, k);
}

void built_trie(int id, int len)
{
    node *p = head;
    for(int i = 0; i < len; i ++)
    {
        int temp = str[i] - 'A';
        if(p->s[temp] == NULL)
        {
            p->s[temp] = new node;
            p->s[temp]->w = 0;
            p->s[temp]->c=str[i];
            for(int j = 0; j < 26; j ++)
                p->s[temp]->s[j]=NULL;
            p->s[temp]->fail=head;
        }
        p = p->s[temp];
    }
    p->w=id;
}

void built_AC()
{
    node *p;
    while(!q.empty()) q.pop();
    for(int i = 0; i < 26; i ++)
        if(head->s[i])
        q.push(head->s[i]);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i = 0; i < 26; i ++)
        {
            if(p->s[i] != NULL)
            {
                q.push(p->s[i]);
                p->s[i]->fail=updateFail(p->fail, i);
            }
        }
    }
    return ;
}

void find(int x, int y, node *p)
{
    if(p == NULL)
        p = head;
    if(p->w && outdata[p->w].x<0)
    {
        outdata[p->w].x=x - t[face][0] * (outdata[p->w].len);
        outdata[p->w].y=y - t[face][1] * (outdata[p->w].len);
        outdata[p->w].c='A' + face;
    }
    if (!(y<c && y>=0 && x<r && x>=0)) return;
    while(p->s[s[x][y]-'A'] == NULL && p != head)
        p=p->fail;
    find(x+t[face][0], y+t[face][1], p->s[s[x][y]-'A']);
    return ;
}

int main ()
{
    int k;
    memset(outdata, -1, sizeof(outdata));
    scanf("%d %d %d", &r, &c, &k);
    for(int i = 0; i < r; i ++)
        scanf("%s", s[i]);

    head = new node;
    head->w = 0;
    head->fail = head;
    for(int i = 0; i < 26; i ++)
        head->s[i]=NULL;

    for(int i = 1; i <= k; i ++)
    {
        scanf("%s", str);
        int len = strlen(str);
        outdata[i].len=len;
        built_trie(i, len);
    }

    built_AC();
    for(face = 0; face < 8; face ++)
    {
        for(int j = 0; j < c; j ++)
        {
            find(0, j, head);
            find(r-1, j, head);
        }
        for(int j = 0; j < r; j ++)
        {
            find(j, 0, head);
            find(j, c-1, head);
        }
    }
    for(int i = 1; i <= k; i ++)
    {
        printf("%d %d %c\n", outdata[i].x, outdata[i].y, outdata[i].c);
    }
    return 0;
}
