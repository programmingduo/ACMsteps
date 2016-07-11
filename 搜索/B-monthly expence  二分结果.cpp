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
            first = cost[i];        //Ҫȷ����СֵҲ���Ƕ��ֵ���С�߽�
    }

    int min = last;
    while(first <= last)           //���ں��ǲ����ٵ�
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
            if(min > mid)        //����Ϊ�˱�֤�����е����ֵ�Ϳ�����Mһ����ɵ����
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
