#include<cstdio>
#include<cmath>
#include<string.h>

using namespace std;

int temp[100];

int main ()
{
    int N;
    memset(temp, 0, sizeof(temp));
    temp[0] = 1;
    temp[1] = 2;
    while(~scanf("%d", &N))
    {
        int ans;
        int i = 1;
        for(; ; i ++)
        {
            if(!temp[i])
                temp[i] = temp[i - 1] * 2;
            if(temp[i] > N)
                break;
        }
        ans = i;
        printf("%d\n", ans);
    }
}
