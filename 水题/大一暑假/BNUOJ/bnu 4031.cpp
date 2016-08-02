#include<iostream>
#include<cstdio>
using namespace std;

const long N = 10000;                   //N��ʾҪ��������ĸ���
long prime[N] = {0},num_prime = 0;    // �洢�����������ĸ���
int isNotPrime[N] = {1, 1};           //һ����������

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

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        printf("%d\n", prime[i]);
    return 0;
}
