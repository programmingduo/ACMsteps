#include<cstdio>
#include<cstring>

const long N = 1000000;                   //N��ʾҪ��������ĸ���
long prime[N] = {0},num_prime = 0;    // �洢�����������ĸ���
int isNotPrime[N] = {1, 1};           //һ����������
int num[N + 5];

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

    memset(num, 0, sizeof(num));
    for(int i = 0; i <= num_prime; i ++)
    {
        int temp = prime[i];
        if(temp > N + 2)
            break;
        while(temp <= N + 2 && temp > 0)
        {
            num[temp] = prime[i];
            temp *= prime[i];
        }
    }

    int n, m;
    scanf("%d", &n);
    while(n --)
    {
        int ans = 1;
        scanf("%d", &m);
        for(int i = 1; i <= m + 1; i ++)
        {
            if(num[i] != 0)
            {
                ans *= num[i];

            }
        }
        ans /= (m + 1);
        printf("%d\n", ans);
    }

    return 0;
}
