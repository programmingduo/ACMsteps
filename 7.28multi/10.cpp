#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
#define maxn 100005
int num[maxn];
int dp[maxn];

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t ++){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        int len = 0;
        for (int i = 0; i < n; i++){
            if(num[i] != 0)
            {
                int low = 0;
                int high = len - 1;
                while(low <= high){
                    int mid = (low + high) / 2;
                    if(dp[mid] < num[i])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                if(low >= len) len++;
                dp[low] = num[i];
            }
            else
            {
                for(int j = len; j > 0; j --)
                {
                    dp[j] = dp[j - 1] + 1;
                }
                dp[0] = -1115555;
                len ++;
            }
            //for (int i = 0; i < 10; i++){
                //cout << dp[i] << " ";
            //}
            //cout << endl;
        }
        printf("Case #%d: %d\n", t, len);
    }
    return 0;
}
