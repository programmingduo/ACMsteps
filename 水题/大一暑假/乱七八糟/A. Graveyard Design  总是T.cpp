#include<iostream>
#include<map>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>

using namespace std;

long long n, sum = 1;
int ans[10000], x[10000], y[10000], num = 0;

void sousuo()
{
    int flag = sqrt(n * 1.0);
    int small = 1, big = 1;
    int total = 0;
    while (big <= flag)
    {
        while(sum < n)
        {
            big ++;
            sum += big * big;
        }
        if(sum == n)
        {
            x[num] = small;
            y[num] = big;
            num ++;
        }
        sum -= small * small;
        small ++;
    }
}

int main ()
{
    scanf("%lld", &n);
    sousuo();
    printf("%d\n", num);
    for(int i = 0; i < num; i ++)
    {
        printf("%d", y[i] - x[i] + 1);
        for(int j = x[i]; j <= y[i]; j ++)
            printf(" %d", j);
        printf("\n");
    }
    return 0;
}
