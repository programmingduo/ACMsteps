#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct question
{
    int id, time;
};

question ques[3005];

bool comp(question a, question b)
{
    if(a.time != b.time)                            //保证什么什么XX不变性
        return a.time < b.time;
    return a.id < b.id;
}

int main ()
{
    int T, num;
    scanf("%d", &T);
    for(int j = 1; j <= T; j ++)
    {
        int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d", &num);
            ques[i].id = i;
            ques[i].time = num;
        }
        sort(ques + 1, ques + m + 1, comp);
        printf("Case %d:", j);
        for(int i = 1; i <= m; i ++)
            printf(" %d", ques[i].id);
        printf("\n");
    }
    return 0;
}
