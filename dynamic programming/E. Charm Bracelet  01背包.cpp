#include<iostream>
#include<cstdio>
using namespace std;

int N, M, ans = 0, weight = 0;
int W[3500], D[3500];
bool flag = 0;
long long result = 0;

void dfs(int a = 0)
{
    if(a != 0)
    {
        weight += W[a];
        ans += D[a];
    }

    int temp = a;
    temp ++;
    while(temp <= N)
    {
        if(weight + W[temp] <= M)
        {
            dfs(temp);
        }
        temp ++;
    }

    if(ans > result)
        result = ans;
    ans -= D[a];
    weight -= W[a];
    return ;
}

int main ()
{
    scanf("%lld%lld", &N, &M);
    for(int i = 1; i <= N; i ++)
    {
        scanf("%lld%lld", &W[i], &D[i]);
        if(W[i] > M)
        {
            i --;
            N --;
        }
    }
    dfs();
    printf("%lld\n", result);
    cout<< result<< endl;

    return 0;
}
