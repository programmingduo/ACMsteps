#include<cstdio>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

struct node
{
    int x, y, po, xp, yp;
}a[500005], b[500005];
queue<node> q;
int n;
int in[500005], ain[500005], bin[500005];

int asearch(node no)
{
    int x = no.x;
    int l = 0, r = n - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(a[mid].x > x)
            r = mid - 1;
        else if(a[mid].x < x)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}

int bsearch(node no)
{
    int y = no.y;
    int l = 0, r = n - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(b[mid].y > y)
            r = mid - 1;
        else if(b[mid].y < y)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}

int cmp1(node x, node y)
{
    return x.x < y.x;
}
int cmp2(node x, node y)
{
    return x.y < y.y;
}

void solve()
{
    while(!q.empty())
        q.pop();
    memset(in, 0, sizeof(in));
    memset(bin, 0, sizeof(bin));
    memset(ain, 0, sizeof(ain));

    q.push(a[0]);
    in[a[0].po] = 1;
    while(!q.empty())
    {
        node no = q.front();
        q.pop();
        int x = no.x, y = no.y, po = no.po;
        int id = asearch(no);
        for(int i = id; i < n; i ++)
        {
            if(ain[i])
                break;
            if(a[i].x == x)
            {
                ain[i] = 1;
                if(in[a[i].po])
                    continue;
                q.push(a[i]);
                in[a[i].po] = 1;
            }
            else
                break;
        }
        id = bsearch(no);
        for(int i = id; i < n; i ++)
        {
            if(bin[i])
                break;
            if(b[i].y == y)
            {
                bin[i] = 1;
                if(in[b[i].po])
                    continue;
                q.push(b[i]);
                in[b[i].po] = 1;
            }
            else
                break;
        }
    }
}

int main ()
{
    while(~scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d %d", &a[i].x, &a[i].y);
            a[i].po = i;
            b[i].x = a[i].x;
            b[i].y = a[i].y;
            b[i].po = i;
        }
        std::sort(a, a + n, cmp1);
        for(int i = 0; i < n; i ++)
        {
            a[i].xp = i;
        }
//        for(int i = 0; i < n; i ++)
//            printf("%d ", a[i].x);
//        printf("\n");

        std::sort(b, b + n, cmp2);
        for(int i = 0; i < n; i ++)
        {
            b[i].yp = i;
        }
//        for(int i = 0; i < n; i ++)
//            printf("%d ", b[i].y);
//        printf("\n");

        solve();
        int ans = 0;
        for(int i = 0; i < n; i ++)
            ans += in[i];
        if(ans == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
