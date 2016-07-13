#include<cstdio>
#include<algorithm>

using namespace std;

int a[100005];

int main()
{
    for(int i = 0; i < 50; i ++)
    {
        a[i * 2 + 1] = 1;
        a[i * 2] = -1;
        int ans = 0;
        do{
            int total = 0, flag = 1;
            for(int j = 1; j <= i * 2; j ++)
            {
                total += a[j];
                if(total > 0)
                    flag = 0;
            }

            ans += flag;
        }while(next_permutation(a, a + i * 2));
        int temp = 1;
        for(int t = 1; t < i; t ++)
            temp *= 3;
        printf("%d %d %d\n", i, ans, temp);
    }
    return 0;
}
