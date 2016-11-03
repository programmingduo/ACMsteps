#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;

int ch[500005][26], fail[500005], val[500005], total[500005];
int AC_total;
char s[1000006];

void AC_init()
{
    memset(ch, 0, sizeof(ch));
    memset(fail, 0, sizeof(fail));
    memset(val, 0, sizeof(val));
    memset(total, 0, sizeof(total));
    AC_total = 1;
}

void AC_insert()
{
    int len = strlen(s), id;
    int u = 0;
    for(int i = 0; i < len; i ++)
    {
        id = s[i] - 'a';
        if(ch[u][id] == 0)
            ch[u][id] = AC_total ++;
        u = ch[u][id];
    }

    val[u] ++;
}

void AC_build()
{
    queue<int> q;
    while(!q.empty())
        q.pop();

    for(int i = 0; i < 26; i ++)
        if(ch[0][i])
            q.push(ch[0][i]);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < 26; i ++)
        {
            int temp = ch[u][i];
            if(temp != 0)
            {
                int v = fail[u];
                while(v && !ch[v][i])
                    v = fail[v];
                fail[temp] = ch[v][i];
                q.push(temp);
            }

        }
    }
}

int AC_find()
{
    int n = strlen(s);
    int j = 0, ans = 0;
    for(int i = 0; i < n; i ++)
    {
        int c = s[i] - 'a';
        while(j && !ch[j][c])
            j = fail[j];
        j = ch[j][c];
        int temp = j;
        while(temp && val[temp] != -1)
        {
            ans += val[temp];
            val[temp] = -1;
            temp = fail[temp];
        }
    }
    return ans;
}

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        AC_init();
        scanf("%d", &n);
        while(n --)
        {
            scanf("%s", s);
            AC_insert();
        }

        scanf("%s", s);
        AC_build();
        int ans = AC_find();

//        int ans = 0;
//        for(int i = 0; i < AC_total; i ++)
//        {
//            if(total[i])
//                ans += val[i];
//        }
        printf("%d\n", ans);

    }
    return 0;
}
