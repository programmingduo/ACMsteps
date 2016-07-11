#include<cstdio>

const int N = 500005;
int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};

void init()
{
    for(int i = 2; i < N; i ++)
    {
        if(!isNotPrime[i])
        {
            prime[num_prime ++] = i;
            isNotPrime[i] = 0;
        }

        for(int j = 0; j < num_prime && i * prime[j] < N; j ++)
        {
            isNotPrime[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main ()
{
    init();
    int num, a, b;
    while(~scanf("%d", &num))
    {
        for(a = 4; a < num / 2 + 1; a ++)
        {
            b = num - a;
            if(isNotPrime[a] && isNotPrime[b])
            {
                printf("%d %d\n", a, b);
                break;
            }
        }
    }
}
