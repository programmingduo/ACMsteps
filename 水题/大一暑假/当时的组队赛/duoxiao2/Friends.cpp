#include<cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int ptop[30], id[10][10], person[10];
int ans = 0;
int people;

//int i;
int a,b;
int count = 0;
int pair2;
void f(int i)
{
    int sum = 0;
    for(int j = 1; j <= people; j ++)
    {
        sum += person[j];
    }
    if(sum > (pair2 - i) * 2)
        return ;

    i++;
    if(i >= pair2){
        return ;
    }
    int a = ptop[i] / 100;
    int b = ptop[i] % 100;
    for (int h = 0; h < 2; h++){
        person[a] = person[a] - h * 2;
        person[b] = person[b] - h * 2;

        for(int i = 0; i < people; i ++)
        {
            if(person[i] < 0){
                person[a] += 2 * h;
                person[b] += 2 * h;
                return;
            }
        }
        bool flag = 0;
        for (int i = 0; i < people; i++){
            if(person[i] != 0){
                flag = true;
                break;
            }
        }
        if(!flag){
            count++;
            person[a] += 2 * h;
            person[b] += 2 * h;
            return ;
        }
        else{
            f(i);
        }
        //printf("h = %d\n", h);
        person[a] = person[a] + h * 2;
        person[b] = person[b] + h * 2;
    }
}

int main ()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i ++)
    {
        int  a, b;
        bool falg = 0;
        memset(person, 0, sizeof(person));
        scanf("%d%d", &people, &pair2);
        for(int j = 0; j < pair2; j ++)
        {
            scanf("%d%d", &a, &b);
            if(pair2 % 2 == 1)
                {falg = 1; continue;}
            ptop[j] = a * 100 + b;
            person[a] ++;
            person[b] ++;
        }

        for(int i = 1; i <= people; i ++)
        {
            if(person[i] % 2 == 1)
                falg = 1;
        }
        if(falg)
        {
            printf("0\n");
            continue;
        }
        f(-1);
        printf("%d\n", count);
        count = 0;
    }
}
