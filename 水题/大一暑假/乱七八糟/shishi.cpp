#include<cstdio>
#include<deque>
#include<algorithm>

using namespace std;


struct node
{
    deque<int> in;
    deque<int> out;
}cow[10001];

int each[10001] = {0};

void bianli(int popular)
{
    each[popular] = 1;
    while(!cow[popular].in.empty())
    {
        int temp = cow[popular].in.back();
        cow[popular].in.pop_back();
        bianli(temp);
    }
}

int main ()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int a, b;
    for(int i = 0; i < M; i ++)
    {
        scanf("%d%d", &a, &b);
        cow[a].out.push_back(b);
        cow[b].in.push_back(a);
    }

    int popular, total = 0;
    for(int i = 1; i <= N; i ++)
    {
        if(cow[i].out.size() == 0)
        {
            total ++;
            popular = i;
        }
    }
    bool flag = 1;
    if(total == 1)
    {
        bianli(popular);
        for(int i = 1; i <= N; i++)
            if(each[i] == 0)
                flag = 0;
        if(flag)
            printf("1\n");
    }
    else
        printf("0\n");

    return 0;
}
