#include<cstdio>
#include<cstring>

using namespace std;

int num[1000006];

int main ()
{
    int T, a, b, maxn;
    scanf("%d", &T);
    memset(num, 0, sizeof(num));
    for(int i = 0; i < T; i ++)
    {
        scanf("%d%d", &a, &b);
        if(b > num[a])
            num[a] = b;
        if(b > maxn)
            maxn = b;
    }

    int first = 0, last = 0;
    for(int i = 1; i <= maxn; i ++)
    {
        if(first == 0 && num[i] != 0)
        {
            first = i;
            last = num[i];
        }
        else if(first != 0 && i <= last && last < num[i])
            last = num[i];

        if(i == last)
        {
            printf("%d %d\n", first, last);
            first = 0;
            last = 0;
        }
        else if(last == maxn)
        {
            printf("%d %d\n", first, last);
            break;
        }
    }
    return 0;
}
