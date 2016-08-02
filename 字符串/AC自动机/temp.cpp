#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 10000 + 50;
const int sigma_size = 128;
int mark[1005][1005], m, n, x, y, trans[1000], res;
char str[1005][1005];

struct ac_machine
{
    int ch[maxn][sigma_size];
    int val[maxn];
    int f[maxn];
    int sz;
    void init() { sz = 1; memset(ch, 0, sizeof(ch)); memset(val, 0, sizeof(val)); memset(f, 0, sizeof(f)); }
    int idx(char c)
    {
        return c - '\0';
    }

    void insert(char * s, int v)
    {
        int u = 0;
        for(int i = 0; s[i]; ++i)
        {
            int c = idx(s[i]);
            if(!ch[u][c])
                ch[u][c] = sz++;
            u = ch[u][c];
        }
        if(val[u] != 0)
        {
            for(int i = 1; i < v; ++i)
                if(trans[i] == val[u]) trans[i] = v;
        }
        val[u] = v;
    }

    void getFail()
    {
        queue<int> q;
        f[0] = 0;
        for(int i = 0; i < sigma_size; ++i)
        {
            if(ch[0][i]) { q.push(ch[0][i]); f[ch[0][i]] = 0; }
            else ch[0][i] = 0;
        }
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(int i = 0; i < sigma_size; ++i)
            {
                int v = ch[u][i];
                if(v)
                {
                    q.push(v);
                    int p = f[u];
                    f[v] = ch[p][i];
                }
                else ch[u][i] = ch[f[u]][i];
            }
        }
    }

    void find()
    {
        for(int a = 0; a < m; ++a)
        {
            int u = 0;
            for(int i = 0; i < n; ++i)
            {
                int c = idx(str[a][i]);
                u = ch[u][c];
                if(val[u])
                {
                    mark[a][i] = val[u];
                    if(val[u] == x && a >= x - 1)
                    {
                        //cout << a << " " << i << "\n";
                        bool sign = true;
                        for(int j = a, k = x; k > 0; --k, --j)
                            if(mark[j][i] != trans[k]) { sign = false; break; }
                        if(sign) res++;
                    }
                }
            }
        }
    }

}ac;


int main()
{
//    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        res = 0; ac.init();
        for(int i = 1; i <= 100; ++i) trans[i] = i;
        memset(mark, 0, sizeof(mark));
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; ++i)
            scanf("%s", str[i]);
        scanf("%d %d", &x, &y);
        for(int i = 0; i < x; ++i)
        {
            char tempstr[104];
            scanf("%s", tempstr);
            ac.insert(tempstr, i + 1);
        }
        ac.getFail();
        ac.find();
        printf("%d\n", res);
    }
    return 0;
}
