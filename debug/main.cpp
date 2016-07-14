#include<cstdio>
<<<<<<< HEAD

int a[1000005], b[10005], next[10005];
int n, m;

void get()
{
    next[0] = next[1] = 0;
    for(int i = 2; i < m; i ++)
    {
        int j = next[i - 1];
        while(j && b[i - 1] != b[j])
            j = next[j];
        next[i] = b[i - 1] == b[j] ? j + 1: 0;
    }
}

int search()
{
    int j = 0, i = 0;
    for(; i < n; i ++)
    {
        if(j == m)
            break;
        if(b[j] == a[i])
            j ++;
        else
        {
            while(b[j] != a[i] && j)
                j = next[j];
            if(b[j] == a[i])
                j ++;
        }
    }
    if(j == m)
        return i - m + 1;
    return -1;
=======
#include<algorithm>

long long a[20];
long long d[100];
long long ca[100];

long long min(long long a, long long b)
{
    return a < b? a: b;
>>>>>>> refs/remotes/origin/master
}

int main ()
{
<<<<<<< HEAD
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        for(int j = 0; j < m; j ++)
            scanf("%d", &b[j]);

        get();
        int ans = search();
        printf("%d\n", ans);
=======
    int n;
    while(~scanf("%d", &n))
    {
        long long ans = 0;
        for(int i = 0; i < n; i ++)
            scanf("%lld", &a[i]);
        if(n < 3)
            printf("0\n");
        else
        {
            int re = 0;
            long long cannot = 0, dou = 0;
            std::sort(a, a + n);
            for(int i = 0; i < n; i ++)
            {
                if(i + 2 > n)
                    break;
                if(i < n - 1 && a[i] == a[i + 1])
                {
                    if(re)
                    {
                        re --;
                        ans ++;
                        i ++;
                    }
                    else
                    {
                        if(i + 2 < n)
                        {
                            ans ++;
                            i += 2;
                        }
                    }
                    continue;
                }
                if(i + 2 > n)
                    continue;
                if(a[i] + a[i + 1] > a[i + 2])
                {
                    ans ++;
                    i += 2;
                }
                else
                    re ++;
            }
            printf("%d\n", ans);
        }
>>>>>>> refs/remotes/origin/master
    }
    return 0;
}
//            for(int i = 1; i < n; i ++)
//            {
//                if(a[i] == a[i -1])
//                {
//                    d[dou++] = a[i];
//                    a[i] = a[i - 1] = 0x7fffffffff;
//                }
//            }
//            std::sort(a, a + n);
////            for(int i = 0; i < n; i ++)
////                printf("%d ", a[i]);
//            for(int i = 0; i < n; i ++)
//            {
//                if(i + 2 >= n || a[i + 2] == 0x7fffffffff)
//                {
////                    printf(" i=%d ", i);
//                    if(i < n && a[i] != 0x7fffffffff)
//                        ca[cannot ++] = a[i];
//                    if(i + 1 < n && a[i + 1] != 0x7fffffffff)
//                        ca[cannot++] = a[i + 1];
//                    if(i + 2 < n && a[i + 2] != 0x7fffffffff)
//                        ca[cannot ++] = a[i +2];
//                    break;
//                }
//                if(a[i] + a[i +1] < a[i + 2])
//                    ca[cannot ++] = a[i];
//                else
//                {
//                    i += 2;
//                    ans ++;
//                }
//            }
////            printf("%d %d %d", ans, dou, cannot);
//            long long re = 0, flag;
//            for(int i = 0, j = 0; i < dou; i ++)
//            {
//                flag = 1;
//                j = 0;
//                while(j < cannot)
//                {
//                    if(d[i] + d[i] > ca[cannot])
//                    {
//                        ca[cannot] = 1000000000000;
//                        flag = 0;
//                        break;
//                    }
//                    j ++;
//                }
//                if(flag)
//                    re ++;
//                else
//                    ans ++;
//            }
//            if(re > 0)
//                ans += re * 2 / 3;
//            printf("%lld\n", ans);
//        }
//
//    }
//}
