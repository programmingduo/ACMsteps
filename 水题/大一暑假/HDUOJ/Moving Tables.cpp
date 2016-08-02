#include<iostream>

using namespace std;

void biaoji(int road[], int from, int to)
{
    int small, big;
    small = min(from, to);
    small = (small + 1) / 2 - 1;
    big = max(from, to);
    big = (big + 1) / 2 - 1;
    for(int i = small; i <= big; i ++)
    {
        road[i] ++;
    }
    return ;
}

int main ()
{
    int N;
    cin>> N;
    for(int i = 0; i < N; i ++)
    {
        int testCase, road[200] = {0};
        cin>> testCase;
        for(int j = 0; j < testCase; j ++)
        {
            int from, to;
            cin>> from>> to;
            biaoji(road, from, to);
        }
        int count = 0;
        for(int j = 0; j < 200; j ++)
        {
            if(road[j] > count)
                count = road[j];
        }
        cout<< count * 10<<endl;
    }
}
