#include<cstdio>
#include<string.h>


const int N = 1399709;
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
    int r, l, n;
    Prime(1399709);
    while(~scanf("%d", &n) && n)
    {
        for(int i = n; i < 1399709; i ++)
        {
            if(!a[i])
            {
                r = i;
                break;
            }
        }
        for(int i = n; i > 0; i --)
        {
            if(!a[i])
            {
                l = i;
                break;
            }
        }
        printf("%d\n", r - l);
    }
    return 0;
}
