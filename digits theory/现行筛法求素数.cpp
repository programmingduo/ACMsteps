#include<iostream>
#include<cstdio>
using namespace std;

const long N = 1000000;                   //N表示要处理的数的个数
long prime[N] = {0},num_prime = 0;    // 存储素数和素数的个数
int isNotPrime[N] = {1, 1};           //一个辅助数组

int main()
{
    for(long i = 2 ; i < N ; i ++)
    {
        if(! isNotPrime[i])
        {
            prime[num_prime ++]=i;
        }

        for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
        {
            isNotPrime[i * prime[j]] = 1;
            if(!(i % prime[j]))
            {
                break;
            }
        }
    }

    for(int i = 0; i < num_prime; i ++)
    {
        printf("%d ", prime[i]);
    }
    return 0;
}
