#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

int city[10005], times[10005];
stack<int> bic[10005];

int main ()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i ++)
    {
        printf("Case %d:\n", i);
        int N, Q;
        scanf("%d%d", &N, &Q);
        getchar();
        for(int j = 1; j <= N; j ++)
        {
            city[j] = j;      //j在那个城市
            times[j] = 0;     //j多少次
            while(!bic[j].empty())  bic[j].pop();
            bic[j].push(j);
        }

        char flag;
        int a, b;
        for(int j = 0; j < Q; j ++)
        {
            scanf("%c", &flag);
            if(flag == 'T')
            {
                scanf("%d%d", &a, &b);     // a球到b成
                getchar();
                int temp0 = city[a];
                for(int k = 0; k < bic[temp0].size();)
                {
                    int temp = bic[temp0].top();
                    bic[temp0].pop();
                    city[temp] = b;
                    times[temp] ++;
                    bic[b].push(temp);
                }
            }
            else if(flag == 'Q')
            {
                scanf("%d", &a);
                getchar();
                printf("%d %d %d\n", city[a], bic[city[a]].size(), times[a]);
            }
        }
    }
    return 0;
}
