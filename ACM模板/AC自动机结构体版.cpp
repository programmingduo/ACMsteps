#include<cstdio>
#include<string.h>
#include<cstring>
#include<queue>

using namespace std;

struct node
{
    int next[26];
    int val, fail;
}AC_node[1100];
int AC_total;
char s[100];
int dp[30][100][2048];

int max(int a, int b)
{
    return a>b? a: b;
}

void AC_init()
{
    AC_total = 1;
    AC_node[0].val = 0;
    for(int i =0; i < 26; i ++)
    {
        AC_node[0].next[i] = 0;
    }
}

int AC_new()
{
    for(int i = 0; i < 26; i ++)
    {
        AC_node[AC_total].next[i] = 0;
    }
    AC_node[AC_total].val = 0;
    AC_node[AC_total].fail = 0;
    return AC_total ++;
}

void AC_insert(char *c, int num)
{
    int len = strlen(c);
    int pos = 0;
    for(int i = 0; i < len; i ++)
    {
        int index = c[i] - 'a';
        if(AC_node[pos].next[index] == 0)
        {
            AC_node[pos].next[index] = AC_new();
        }
        pos = AC_node[pos].next[index];
    }
    AC_node[pos].val |= 1<<num;
}

void AC_build()
{
    queue<int> q;
    while(!q.empty())
        q.pop();

    for(int i = 0; i < 26; i ++)
    {
        int temp = AC_node[0].next[i];
        if(temp)
        {
            AC_node[temp].fail = 0;
            q.push(temp);
        }
    }

    while(!q.empty())
    {
        int id = q.front();
        q.pop();
        AC_node[id].val |= AC_node[AC_node[id].fail].val;
        for(int i = 0; i < 26; i ++)
        {
            if(AC_node[id].next[i])
            {
                AC_node[AC_node[id].next[i]].fail = AC_node[AC_node[id].fail].next[i];
                q.push(AC_node[id].next[i]);
            }
            else
                AC_node[id].next[i] = AC_node[AC_node[id].fail].next[i];
        }
    }
//    for(int i = 0; i < AC_total; i ++)
//    {
//        printf("%d %d\n", i, AC_node[i].val);
//    }

}

int solve(int n, int m, int k)
{
    for(int i = 0; i <= n; i ++)
        for(int j = 0;j <= AC_total; j ++)
            for(int l = 0; l < 1 << m; l ++)
            dp[i][j][l] = 0;
//因为数组的范围并不精确，因此使用memset反而会比较慢
//    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < AC_total; j ++)
        {
            for(int l = 0; l < 1<<(m); l ++)
            {
                if(dp[i][j][l])
                {
                    for(int h = 0; h < 26; h ++)
                    {

                        dp[i+1][AC_node[j].next[h]][AC_node[AC_node[j].next[h]].val|l] += dp[i][j][l];
                        dp[i+1][AC_node[j].next[h]][AC_node[AC_node[j].next[h]].val|l] %= 20090717;
                    }
                }
            }
        }
    }
    int ans = 0, total, temp;
    for(int j = 0; j < 1<<(m); j ++)
    {
        total = 0;
        temp = j;
        while(temp)
        {
            total += temp&1;
            temp>>= 1;
        }
        if(total < k)
            continue;
        for(int i = 0; i < AC_total; i ++)
        {
            if(dp[n][i][j])
            {
                ans+= dp[n][i][j];
                ans %= 20090717;
            }
        }
    }

    return ans % 20090717;
}

int main ()
{
    int n, m, k;
    while(~scanf("%d %d %d", &n, &m, &k) && (n+m+k))
    {
        AC_init();
        for(int i = 0; i < m; i ++)
        {
            scanf("%s", s);
            AC_insert(s, i);
        }
        AC_build();
        int ans = solve(n, m, k);
        printf("%d\n", ans);
    }
}
