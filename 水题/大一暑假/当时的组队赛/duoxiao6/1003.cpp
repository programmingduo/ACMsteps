#include<cstdio>
#include<cstring>

using namespace std;

int num[100005];

int main ()
{
    int n, T, m, total[15];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        int temp = (n + 1) * n / 2;
        if(temp % m == 0)
        {
            memset(num, 0, sizeof(int) * (n + 3));
            memset(total, 0, sizeof(total));
            printf("YES\n");
            temp /= m;
            while(m --)
            {
                int total = 0;
            }
        }
        else
        {
            printf("NO\n");
        }
    }
}
