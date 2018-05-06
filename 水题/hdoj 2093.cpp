#include <cstdio>
#include <string.h>
#include <algorithm>

struct node{
    char name[14];
    int score;
    int time;
}stu[10000];

int cmp(node a, node b)
{
    if(a.score != b.score)
        return a.score > b.score;
    if(a.time != b.time)
        return a.time < b.time;
    if(strcmp(a.name, b.name) < 0)
       return 1;
    else
        return 0;
}

char in[2000];

int main ()
{
    int n, m, id, temp;
    scanf("%d %d", &n, &m);
    int total = -1;
    while(~scanf("%s", stu[++ total].name))
    {
        stu[total].score = 0;
        stu[total].time = 0;
        for(int j = 0; j < n; j ++)
        {
            scanf("%s", in);
            if(in[0] == '-' || in[0] == '0')
            continue;
            id = 0;
            stu[total].score ++;

            temp = 0;
            while(in[id] && in[id] != '(')
            {
                temp = temp * 10 + in[id] - '0';
                id ++;
            }

            stu[total].time += temp;

            temp = 0;
            if(in[id] != '(')
               continue;
            id ++;
            while(in[id] && in[id] != ')')
            {
                temp = temp * 10 + in[id] - '0';
                id ++;
            }
            stu[total].time += temp * m;
        }
    }
    std::sort(stu, stu + total, cmp);

    for(int i = 0; i < total; i ++)
    {
        printf("%-10s %2d %4d\n", stu[i].name, stu[i].score, stu[i].time);
    }

    return 0;
}
