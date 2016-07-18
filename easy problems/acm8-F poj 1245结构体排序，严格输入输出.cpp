#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string.h>

using namespace std;

struct node
{
    string name;
    int time[7];
    int problem, total, average;
    int  pos;
}team[25];

void compute(node &a)
{
    double temp = 0;
    int to = 0;
    a.problem = 0;
    a.total = 0;
    for(int i = 0; i < 7; i ++)
    {
        if(a.time[i] != 0)
        {
            to ++;
            temp += log(a.time[i]);
            a.problem ++;
            a.total += a.time[i];
        }
    }
    if(to == 0)
    {
        a.average = 0;
        return ;
    }
    temp = exp(temp / (1.0 * to));
    //
    a.average = temp + 0.5;
}

int comp(node a, node b)
{
    if(a.problem != b.problem)
        return a.problem > b.problem;
    if(a.total != b.total)
        return a.total < b.total;
    if(a.average != b.average)
        return a.average < b.average;
    return a.name < b.name;
}

int same(node a, node b)
{
    return (a.problem == b.problem && a.total == b.total && a.average == b.average);
}

int main ()
{
    int n, T = 1;;
    while(~scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i ++)
        {
            cin>> team[i].name;
            for(int j = 0; j < 7; j ++)
            {
                scanf("%d", &team[i].time[j]);
            }
        }
        for(int i = 0; i < n; i ++)
        {
            compute(team[i]);
        }
        sort(team, team + n, comp);
        team[0].pos = 1;
        for(int i = 1; i < n; i ++)
        {
            if(same(team[i], team[i - 1]))
            {
                team[i].pos = team[i - 1].pos;
            }
            else
                team[i].pos = i + 1;
        }
        printf("CONTEST %d\n", T ++);
        for(int i = 0; i < n; i ++)
        {
            if(team[i].pos < 10)
                printf("0");
            printf("%d ", team[i].pos);
            cout<< team[i].name<< " ";
            for(int j = team[i].name.length(); j < 10; j ++)
                printf(" ");
            printf("%d ", team[i].problem);
//            if(team[i].total < 10)
//                printf("   ");
//            else if(team[i].total < 100)
//                printf("  ");
//            else if(team[i].total < 1000)
//                printf(" ");
            printf("%4d ", team[i].total);

//            if(team[i].average < 10)
//                printf("  ");
//            else if(team[i].average < 100)
//                printf(" ");
            printf("%3d", team[i].average);

            for(int j = 0; j < 7; j ++)
            {
//                if(team[i].time[j] < 10)
//                    printf("  ");
//                else if(team[i].time[j] < 100)
//                    printf(" ");
                printf(" %3d", team[i].time[j]);
            }
            printf("\n");
        }
    }
}
