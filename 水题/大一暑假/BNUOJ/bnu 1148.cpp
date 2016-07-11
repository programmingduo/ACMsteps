#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

int main ()
{
    int N, K, n, in[1005], coin[1005], first = 1;
    char result;
    memset(coin, 0, 1005);
    scanf("%d%d", &N, &K);
    while(K --)
    {
        scanf("%d", &n);
        for(int i = 0; i < n * 2; i ++)
            scanf("%d", &(in[i]));
        std::cin>> result;
        switch(result)
        {
        case '=':
            for(int i = 0; i < n * 2; i ++)
                coin[in[i]] = 100000;
            break;
        case '<':
            for(int i = 0; i < n; i ++)
                coin[in[i]] -= 1;
            for(int i = n; i < n * 2; i ++)
                coin[in[i]] += 1;
            break;
        case '>':
            for(int i = 0; i < n; i ++)
                coin[in[i]] += 1;
            for(int i = n; i < n * 2; i ++)
                coin[in[i]] -= 1;
            break;
        }
    }
    int ans = 0, maxw = 0;
    for(int i = 1; i <= N; i ++)
    {
        if(coin[i] < 10000)
        {
            int temp = std::max(coin[i], -coin[i]);
            if(maxw < temp)
                ans = i, maxw = temp;
            else if(maxw == temp)
                ans = 0;
        }
    }
    if(ans == 0)
    {
        int temp = 0;
        for(int i = 1; i <= N; i ++)
        {
            if(coin[i] == 100000)
                continue;
            else if(coin[i] == 0)
            {
                temp ++;
                if(temp == 1)
                    ans = i;
                else if(temp > 1)
                {
                    ans = 0;
                    break;
                }
            }
            else
            {
                ans = 0;
                break;
            }
        }
    }
    std::cout<< ans<< std::endl;
    return 0;
}
