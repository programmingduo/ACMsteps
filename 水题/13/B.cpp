#include <iostream>
#include <cstdio>

using namespace std;
#define mod 1000000007
int dp[100][3];

int main()
{
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    for (int i = 1; i <  100; i++){
        dp[i][0] = ((dp[i-1][0] + dp[i-1][1]*4)%mod + dp[i-1][2]*7)%mod;
        dp[i][1] = dp[i-1][0]*2 + dp[i-1][1]*5 + dp[i-1][2]*8;
        dp[i][2] = dp[i-1][0]*3 + dp[i-1][1]*6 + dp[i-1][2]*9;
    }
    for (int i = 1; i < 20; i++){
        cout << "i = " << i << endl;
        cout << "\t" << dp[i][0] << endl;
        cout << "\t" << dp[i][1] << endl;
        cout << "\t" << dp[i][2] << endl;
    }
    return 0;
}
