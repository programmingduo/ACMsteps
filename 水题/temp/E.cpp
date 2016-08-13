#include<cstdio>
#include<map>
#include<set>
using namespace std;

map<int, int> ma;
map<int, int>::iterator it;
int a[50000];

struct node
{
    int x, y, po, ans;
}le[100005];

int cmp(node x, node y)
{
    if(x.x == y.x)
    return
}

int main ()
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i ++)
            ma[a[i]] ++;

        int temp = 0;
        for(it = ma.begin(); it != ma.end(); it ++)
        {
            it->second = temp ++;
        }
        for(int i = 0; i < n; i++)
        {
            a[i] = ma[a[i]];
//            printf("%d ", a[i]);
        }

        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d", &le[i].x, &le[i].y);
            le[i].po = i;
        }
        sort(le, le + m, cmp);
    }
}
