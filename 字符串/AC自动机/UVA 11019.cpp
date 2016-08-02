#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;

char s1[1005][1005], s2[105][105];
int ch[100056][128], same[200005], trans[200005], fail[200006], val[200005], yes[1005][1005];
int n, m, x, y, AC_total;

void AC_init()
{
    memset(ch, 0, sizeof(ch));
    memset(same, 0, sizeof(same));
    memset(fail, 0, sizeof(fail));
    memset(val, 0, sizeof(val));
    memset(trans, 0, sizeof(trans));
    AC_total = 1;
}

void setval(int id, int value)
{
    if(val[id])
        trans[value] = val[id];
    else
        val[id] = value;
}

void AC_insert(int id)
{
    int len = strlen(s2[id]);
    int u = 0;
    for(int i = 0; i < len; i ++)
    {
        int index = s2[id][i] - '\0';
        if(!ch[u][index])
            ch[u][index] = AC_total ++;
        u = ch[u][index];
    }
    setval(u, id);
}

void AC_getfail()
{
    queue<int> q;
    while(!q.empty())
        q.pop();

    for(int i = 0; i < 128; i ++)
    {
        if(ch[0][i])
        {
            int t = ch[0][i];
            fail[t] = 0;
            q.push(t);
        }
        else
        ch[0][i] = 0;
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < 128; i ++)
        {
            if(ch[u][i])
            {
                q.push(ch[u][i]);
                fail[ch[u][i]] = ch[fail[u]][i];
            }
            else
                ch[u][i] = ch[fail[u]][i];
        }
    }
}

int AC_search()
{
    memset(yes, 0, sizeof(yes));
    for(int i = 1; i <= n; i ++)
    {
        int u = 0;
        for(int j = 1; j <= m; j ++)
        {
            int index = s1[i][j] - '\0';
            u = ch[u][index];
            if(val[u])
                yes[i][j] = val[u];

        }
    }

    int ans = 0;
    for(int i = 1; i <= n-x+1; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(yes[i][j] == 1)
            {
                int flag = 1;
                for(int k = 1; k <= x && flag; k ++)
                {
                    flag = 0;
                    if(yes[i+k-1] == 0)
                        break;
                    if(yes[i+k-1][j] == k || trans[k] == yes[i+k-1][j])
                        flag = 1;
                }
                if(flag)
                    ans ++;
            }
        }
    }
    return ans;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        AC_init();
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%s", s1[i]+1);
        }

        scanf("%d %d", &x, &y);
        for(int i = 1; i <= x; i ++)
        {
            scanf("%s", s2[i]);
            AC_insert(i);
        }
        AC_getfail();
        printf("%d\n", AC_search());
    }
    return 0;
}
