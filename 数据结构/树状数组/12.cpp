#include<cstdio>
#include<algorithm>
#include<map>
#include<string.h>

using namespace std;

int a[50006], b[50005], id1[50005], id2[50005], id3[50005], id4[50005], add1[50005], add2[50005],add3[50005], add4[50005];
int total;
map<int, int> m;

int lowbit(int a)
{
    return a&-a;
}

int add(int i, int val, int *c)
{
    while(i <= total)
    {
        c[i] += val;
        i += lowbit(i);
    }
}

int sum(int i, int *c)
{
    int s = 0;
    while(i > 0)
    {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        m.clear();
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        int last = -1;
        total = 1;
        for(int i = 0; i < n; i ++)
        {
            if(b[i] == last)
                continue;

            m[b[i]] = total ++;
//            printf("%d %d\n", b[i], m[b[i]]);
            last = b[i];
        }
//        for(int i = 0; i < n; i ++)
//            printf("%d ", b[i]);
//        printf("\n");

        for(int i = 0; i < n; i ++)
            a[i] = m[a[i]];

        for(int i = 0; i < n; i ++)
            b[n - i] = a[i];
        for(int i = 0; i < n; i ++)
            a[i + 1] = b[n - i];

//        for(int i = 1; i <= n; i ++)
//            printf("%d ", a[i]);
//        printf("\n");
//
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", b[i]);
//        printf("\n");

        memset(add1, 0, sizeof(add1));
        memset(add2, 0, sizeof(add2));
        memset(add3, 0, sizeof(add3));
        memset(add4, 0, sizeof(add4));
        for(int i = 1; i <= n; i ++)
        {
            id2[i] = sum(a[i] - 1, add2);
            add(a[i], 1, add2);

            id3[n - i + 1] = sum(b[i] - 1, add3);
            add(b[i], 1, add3);

            id4[i] = sum(total - a[i] - 1, add4);
            add(total - a[i], 1, add4);

            id1[n - i + 1] = sum(total - b[i] - 1, add1);
            add(total - b[i], 1, add1);
        }

        long long ans1 = 0, ans2 = 0, ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            ans1 += id1[i];
            ans2 += id3[i];
        }
        ans = ans1 * ans2;

//        for(int i = 1; i <= n; i ++)
//            printf("%d ", id1[i]);
//        printf("\n");
//
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", id2[i]);
//        printf("\n");
//
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", id3[i]);
//        printf("\n");
//
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", id4[i]);
//        printf("\n");



        for(int i = 1; i <= n; i ++)
        {
            ans -= id1[i] * id3[i] + id1[i] * id4[i] + id2[i] * id3[i] + id2[i] * id4[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
