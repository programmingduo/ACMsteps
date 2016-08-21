#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
long long dis[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4}; //0
long long shiji[10] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8}; //10
long long jishi[10] = {6, 6, 5, 5, 5, 7, 6, 6}; //20

long long solve(int n){

        int t = n;
        int cnt = 0;

        int ge = n % 10;
        n/=10;
        int shi = n % 10;
        n/=10;
        int bai = n % 10;
        n/=10;
        int qian = n % 10;

        if(qian >= 1) return 11;
        if(bai >= 1) cnt = 3;
        else if(shi >= 1) cnt = 2;
        else if(ge >= 1) cnt = 1;


        if(cnt == 1)
        {
            return dis[t];
        }
        if(cnt == 2 && shi == 1)
        {
            return shiji[t - 10];
        }
        if(cnt == 2)
        {
            return jishi[t / 10 - 2] + dis[t % 10];
        }
        if(cnt == 3)
        {
            if(shi == 1)
                return dis[t / 100] + 10 + shiji[t % 100 - 10];
            if(shi == 0 && ge == 0)
                return dis[t / 100] + 7;
            if(shi == 0)
                return dis[t / 100] + 10 + dis[t % 10];
            return dis[t / 100] + 10 + jishi[((t / 10) % 10) - 2] + dis[t % 10];
        }
}

int main()
{
    int t, n;
    scanf("%d", &t);
    long long res = 0;
    while(t--){
        scanf("%d", &n);
        long long ans = 0;
//        printf("%lld\n", solve(n));
        for (int i = 1; i <= n; i++){
            ans += solve(i);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
