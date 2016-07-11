#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int a[4001], b[4001], c[4001], d[4001], sum[16000001], sum1[16000001];

int search(const int aim, int first, int last)
{
    if(first > last || sum[first] > aim || sum[last] < aim)
        return 0;

    int mid = (first + last) >> 1;    //”ä’¼Ú/2‰õˆê“_

    if(sum[mid] > aim)
        return search(aim, first, mid - 1);
    else if(sum[mid] < aim)
        return search(aim, mid + 1, last);
    else
        return (search(aim, first, mid - 1) + search(aim, mid + 1, last) + 1);
}

int main()
{
    int test;
    scanf("%d", &test);

    for(int i = 0; i < test; i ++)
    {
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }

    int x = 0, y = 0;
    for(int i = 0; i < test; i ++)
        for(int j = 0; j < test; j ++)
        {
            sum[x ++] = a[i] + b[j];
            sum1[y] = c[i] + d[j];
            sum1[y] = -sum1[y];
            y ++;
        }

    sort(sum, sum + x);
    sort(sum1, sum1 + x);

    int j = 0, ans = 0;
    for(int i = 0; i < x; i ++)
    {
        ans += search(sum1[i], 0, x - 1);
    }

    printf("%d\n", ans);
    return 0;
}
