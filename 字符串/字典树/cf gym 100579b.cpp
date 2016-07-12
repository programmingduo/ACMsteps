#include<cstdio>
#include<string.h>

struct Trie{
    int ch[1000009][26];
    int sz;

    void clean()
    {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }

    int idx(char a)
    {
        return a - 'a';
    }

    int insert(char *s)
    {
        int n = strlen(s), u = 0, flag = 1, ans = 0;
        for(int i = 0; i < n; i ++)
        {
            int c = idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                if(flag)
                {
                    ans = i;
                    flag = 0;
                }
                ch[u][c] = sz ++;
            }
            u = ch[u][c];
        }
        if(flag)
            return n;
        else
            return ans + 1;
    }
}*trie;

char s[1000006];

int main ()
{
    int T, n, ans;
    scanf("%d", &T);
    trie = new Trie;
    for(int t = 1; t <= T; t ++)
    {
        trie->clean();
        ans = 0;
        scanf("%d", &n);
        for(int i= 0; i < n; i ++)
        {
            scanf("%s", s);
            ans += trie->insert(s);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
