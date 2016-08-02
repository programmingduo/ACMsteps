#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 10001;                   //N��ʾҪ��������ĸ���
int prime[N] = {0},num_prime = 0;    // �洢�����������ĸ���
int isNotPrime[N] = {1, 1};           //һ����������
int main()
{
    for(int i = 2 ; i < N ; i ++)
    {
        if(! isNotPrime[i])
        {
            prime[num_prime ++]=i;
        }

        for(int j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
        {
            isNotPrime[i * prime[j]] = 1;
            if(!(i % prime[j]))
            {
                break;
            }
        }
    }
    int num, cases;
    scanf("%d", &cases);

    while(cases --)
    {
        scanf("%d", &num);
        int last = 1000000000, temp = 0, j;
        for(int i = 0; i < N; i ++)
        {
            temp = abs(prime[i] * prime[i] - num);
            if(temp < last)
                last = temp, j = i;
            else
                break;
        }
        printf("%d\n", prime[j] * prime[j]);
    }
    return 0;
}
