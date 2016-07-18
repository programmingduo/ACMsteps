#include<cstdio>

using namespace std;

int cost[100001];

int main ()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int last = 0, first = 0;
    for(int i = 0; i < N; i ++)
    {
        scanf("%d", &cost[i]);
        last += cost[i];
        if(cost[i] > first)
            first = cost[i];        //要确定最小值也就是二分的最小边界
    }

    int min = last;
    while(first <= last)           //等于号是不可少的
    {
        int mid = (first + last) >> 1;
        int total = 0, amount = 1;
        for(int i = 0; i < N; i ++)
        {
            total += cost[i];
            if(total > mid)
            {
                total = cost[i];
                amount ++;
                if(amount > M)
                    break;
            }
        }

        if(amount > M)
        {
            first = mid + 1;
        }
        else if(amount < M)
        {
            if(min > mid)        //这是为了保证输入中的最大值就可以在M一下完成的情况
                min = mid;
            last = mid - 1;
        }
        else
        {
            if(min > mid)
            {
                min = mid;
            }
            last = mid - 1;
        }
    }
    printf("%d", min);

    return 0;
}
