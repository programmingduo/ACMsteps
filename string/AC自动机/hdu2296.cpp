#include<cstdio>
#include<string.h>
#include<cstring>
#include<iostream>
#include<queue>
#include<string>

using namespace std;

char s[105][14];
int val[1505], trie_total, dp[55][1500], fail[1505], ch[2000][26];
string path[55][1500];

void AC_init()
{

    memset(ch, 0, sizeof(ch));
    memset(fail, 0, sizeof(fail));
    memset(val, 0, sizeof(val));
    trie_total = 1;
}

void AC_insert(int id, int value)
{
    int len = strlen(s[id]), index;
    int u = 0;
    for(int i = 0; i < len; i ++)
    {
        index = s[id][i] - 'a';
        if(ch[u][index] == 0)
            ch[u][index] = trie_total ++;
        u = ch[u][index];
    }
    val[u] = value;
}

void AC_build()
{
    queue<int > q;
    while(!q.empty())
        q.pop();
    for(int i = 0; i < 26; i ++)
        if(ch[0][i])
        {
            q.push(ch[0][i]);
            fail[ch[0][i]] = 0;
        }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        val[u] += val[fail[u]];
        for(int i = 0; i < 26; i ++)
        {
            int temp = ch[u][i];
            if(temp != 0)
            {
                fail[temp] = ch[fail[u]][i];
                q.push(temp);
            }
            else
            {
                ch[u][i] = ch[fail[u]][i];
            }
        }
    }
}

void solve(int n)
{
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    path[0][0] = "";
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < trie_total; j ++)
        {
            if(dp[i][j] != -1)
            {
                for(int k = 0; k < 26; k ++)
                {
                    int temp = ch[j][k];
                        if(dp[i+1][temp] < dp[i][j] + val[temp])
                        {
                            dp[i+1][temp] = dp[i][j] + val[temp];
                            path[i+1][temp] = path[i][j] + (char)('a' + k);
                        }
                        else if(dp[i+1][temp] == dp[i][j] + val[temp])
                        {
                            string str = path[i][j] + (char)('a' + k);
                            if(str<path[i+1][temp])
                                path[i+1][temp] = str;
                        }
                }
            }
        }
    }

    int maxans = 0xffffffff, row, id;
    for(int i = 0; i <= n; i ++)
    {
        for(int j = 0; j < trie_total; j ++)
        {
            if(dp[i][j] > maxans)
            {
                row = i;
                id = j;
                maxans = dp[i][j];
            }
            else if(dp[i][j] == maxans)
            {
                if(path[row][id].length() > path[i][j].length())
                {
                    row = i;
                    id = j;
                }
                else if(path[row][id].length() == path[i][j].length() && path[row][id] > path[i][j])
                {
                    row = i;
                    id = j;
                }
            }
        }
    }
    cout<< path[row][id]<< endl;
}

int main ()
{
    int T, n, m, sval;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &n, &m);
        AC_init();
        for(int i = 0; i < m; i ++)
        {
            scanf("%s", s[i]);
        }
        for(int i = 0; i < m; i ++)
        {
            scanf("%d", &sval);
            AC_insert(i, sval);
        }

        AC_build();
        solve(n);
    }
    return 0;
}
