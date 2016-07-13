#include<cstdio>

int a[5000], b[5000];

int main ()
{
    int i = 1, t = 0;
    while(i * (i + 1) / 2 <= 990528)
    {
        a[t ++] = i * (i + 1) / 2;
        i ++;
    }
    int i0 = 1, t0 = 0;
    while(i0 * (i0 * 2 - 1) <= 990528)
    {
        b[t0 ++] = i0 * (i0 * 2 - 1);
        i0 ++;
    }

    int j = 0;
    i = 0;
    while(i < t && j < t0)
    {
        if(a[i] < 2016)
        {
            i ++;
            continue;
        }
        if(b[j] < 2016)
        {
            j ++;
            continue;
        }
        if(a[i] == b[j])
        {
            if(a[i] % 4 == 0 && a[i] % 100 != 0 || a[i] % 400 == 0)
                printf("%d\n", a[i]);
            i ++, j ++;
        }
        else if(a[i] < b[j])
        {
            i ++;
        }
        else
            j ++;
    }
    return 0;
}
