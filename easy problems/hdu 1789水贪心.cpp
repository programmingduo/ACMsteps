#include<cstdio>
#include<string.h>
#include<algorithm>

struct node
{
    int dead, score;
}subject[1005];
int used[1008];

int cmp(node a, node b)
{
    return a.score > b.score;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int ans = 0, n;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &subject[i].dead);
        for(int i = 0; i < n; i ++)
            scanf("%d", &subject[i].score);
        std::sort(subject, subject + n, cmp);
        memset(used, 0, sizeof(used));
        for(int i = 0; i < n; i ++)
        {
            int flag = 0;
            for(int j = subject[i].dead; j > 0; j --)
            {
                if(!used[j])
                {
                    flag = 1;
                    used[j] = 1;
                    break;
                }
            }
            if(!flag)
                ans += subject[i].score;
        }
        printf("%d\n", ans);
    }
    return 0;
}
