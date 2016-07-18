#include<cstdio>
#include<deque>
#include<algorithm>
#include<string.h>
#include<iterator>
#include<vector>
using namespace std;
struct node
{
    vector<int> in;
}cow[10001];
int each[10001] = {0};
int total = 0;
void bianli(int popular)
{
    if(each[popular] != 1)
    {
        each[popular] = 1;
        total ++;
    }
    vector<int>::iterator temp = cow[popular].in.begin();
    while(temp != cow[popular].in.end())
    {
        int num = *temp;
        if(each[num] != 1)
            bianli(num);
        temp ++;
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
        cow[b].in.push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= N; i ++)
    {
        total = 0;
        bianli(i);
        bool flag = 0;
        if(total == N)
            ans ++;
        memset(each, 0, (sizeof(int) * N + 1));
    }
    printf("%d", ans);
    return 0;
}
