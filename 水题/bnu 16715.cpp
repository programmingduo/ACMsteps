#include<cstdio>
#include<algorithm>
using namespace std;

int till[100005];

int main ()
{
    int T, n, a, b, temp, ans;
    scanf("%d", &T);
    while(T --)
    {
        ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            till[i] = i + 1;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &a, &b);
            if(till[a] < b + 1)
                till[a] = b + 1;
        }
        a = 1, b = till[1];
        ans = 1;
        while(b <= n)
        {
            temp = b;
            for(; a <= b; a ++)
            {
                temp = max(till[a], temp);
            }
            b = temp;
            ans ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
