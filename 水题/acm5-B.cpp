#include<cstdio>

char tele[15];

bool check1()
{
    for(int j = 7; j <= 10; j ++)
    {
        if(tele[j] != tele[j - 1])
            return 0;
    }
    return 1;
}

bool check21()
{
    for(int j = 7; j <= 10; j ++)
    {
        if(tele[j] != tele[j - 1] + 1)
            return 0;
    }
    return 1;
}

bool check22()
{
    for(int j = 7; j <= 10; j ++)
    {
        if(tele[j] != tele[j - 1] - 1)
            return 0;
    }
    return 1;
}

bool check3()
{
    int year, month, day;
    year = (tele[3] - '0') * 1000 + (tele[4] - '0') * 100 + (tele[5] - '0') * 10 + tele[6] - '0';
    month = (tele[7] - '0') * 10 + tele[8] - '0';
    day = (tele[9] - '0') * 10 + tele[10] - '0';
    if(year < 1980 || year > 2016 || month > 12 || day > 31 || month == 0 || day == 0)
        return 0;
    if(month == 1 || month == 3 || month == 5|| month == 7|| month == 8|| month == 10|| month == 12)
        return 1;
    else if(month == 2)
    {
        if(year % 4 == 0 && day < 30)
            return 1;
        if(year % 4 != 0 && day < 29)
            return 1;
    }
    else if(day < 31)
        return 1;
    return 0;
}

int main ()
{
    int T, n, a, b, flag;
    long long ans;
    scanf("%d", &T);
    while(T --)
    {
        ans = 0;
        scanf("%d", &n);
        scanf("%d%d", &a, &b);
        for(int i = 0; i < n; i ++)
        {
            flag = 1;
            scanf("%s", tele);
            flag = check1() || check21() || check22() || check3();
            if(flag)
                ans += a;
            else
                ans += b;
        }
        printf("%lld\n", ans);
    }
}
