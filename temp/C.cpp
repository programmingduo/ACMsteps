#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

int n, s, mod;
int val[500005];
struct node
{
    int id, v;
}sn[500005];

bool operator < (node n1, node n2)
{
    if(n1.v == n2.v)
        return n1.id > n2.id;
    return n1.v < n2.v;
}

priority_queue<node> q;
vector<int> ans;

void solve()
{
    node temp;
    temp.id = s;
    val[s] = 1;
    q.push(temp);
    ans.clear();
    while(!q.empty())
    {
        temp = q.top();
        int id = temp.id;
        ans.push_back(id);
        q.pop();

        if(id / 2 && !val[id / 2])
        {
            val[id / 2] = 1;
            temp.id = id / 2;
            temp.v = (id - id / 2) % mod;
            q.push(temp);
        }

        if(id * 2 <= n && !val[id * 2])
        {
            val[id * 2] = 1;
            temp.id = id * 2;
            temp.v = id % mod;
            q.push(temp);
        }
        if(id * 2 + 1 <= n && !val[id * 2 + 1])
        {
            val[id * 2 + 1] = 1;
            temp.id = id * 2 + 1;
            temp.v = (id + 1) % mod;
            q.push(temp);
        }

    }
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d %d", &n, &s, &mod);
        memset(val, 0, sizeof(val));
        for(int i = 1; i <= n; i ++)
        {
//            if(i / 2)
//                val[i] = max(val[i], (i - i / 2) % mod);
//            if(i * 2 <= n)
//                val[i] = max(val[i], i % mod);
//            if(i * 2 + 1 <= n)
//                val[i] = max(val[i], (i + 1) % mod);
            sn[i].id = i;
            sn[i].v = 0;
        }

        solve();
        for(int i = 0; i < n; i ++)
        {
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
