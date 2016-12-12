#include <cstdio>
#include <string.h>

const int N = 25600000;
bool a[N];
int prime[N], num;


//a[i] = 0表示i为素数
//prime[i]存储第i个素数
//num存储一共多少个素数
void Prime(int n)       //n表示最大界,但是不包括n
{
    memset(a, 0, n * sizeof(a[0]));
    num = 0;
    a[0] = a[1] = 1;
    //不要冒昧的吧<改成<=
    //不然会错。亲测
    for(int i = 2; i < n; ++i)
    {
        if(!(a[i])) prime[num ++] = i;
        for(int j = 0; j < num && i * prime[j] < n; ++j)
        {
            a[i * prime[j]] = 1;
            if(!(i % prime[j])) break;
        }
    }
}

int main ()
{
    Prime(200005);
    printf("%d\n", num);
    for(int i =0; i < num; i ++)
    {
        printf("%d ", prime[i]);
    }
    printf("\n");
    for(int i = 0; i < 100; i ++)
        if(!a[i])
        printf("%d ", i);
    return 0;
}
