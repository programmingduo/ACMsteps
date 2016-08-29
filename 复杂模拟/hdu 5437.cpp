#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct node
{
    char name[204];
    int v, id;
}person[150005];
struct node2
{
    int id, num;
}in[1500004];
int ans[150005];

int cmp2(node2 a, node2 b)
{
    return a.id < b.id;
}

priority_queue<node> que;
bool operator < (const node a, const node b)
{
    if(a.v == b.v)
        return a.id > b.id;
    return a.v < b.v;
}

int main ()
{
    int T, n, m, q, qq;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d %d", &n, &m, &q);
        for(int i = 0; i < n; i ++)
        {
            scanf("%s %d", person[i].name, &person[i].v);
            person[i].id = i;
        }

        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d", &in[i].id, &in[i].num);
        }
        sort(in, in + m, cmp2);

        int j = 0, total = 1;
        for(int i = 0; i < m; i ++)
        {
            while(j < in[i].id)
            {
                que.push(person[j]);
                j ++;
            }

            while(in[i].num --)
            {
                if(que.empty())
                    break;
                 node temp = que.top();
                 que.pop();
                 ans[total ++] = temp.id;
            }
        }
        while(j < n)
        {
            que.push(person[j]);
            j ++;
        }
        while(total <= n)
        {
            node temp = que.top();
            que.pop();
            ans[total ++] = temp.id;
        }

        for(int i = 0; i < q; i ++)
        {
            scanf("%d", &qq);
            if(i)
                printf(" ");
            printf("%s", person[ans[qq]].name);
        }
        printf("\n");
    }
    return 0;
}
