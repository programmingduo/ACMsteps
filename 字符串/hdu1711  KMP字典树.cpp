#include<cstdio>

using namespace std;

int a[1000005], b[10005];   //a是字典，b是目标数字
int next[10005];            // next记录了b中每一个字符前与开头有多少个是一样的

void get_next(int M)        //初始化目标，M为目标的长度
{
    int j = 0, k = -1;
    next[0] = -1;
    while(j < M)
    {
        if(k == -1 || b[j] == b[k])
            next[++j] = ++k;
        else
            k = next[k];
    }
}

int KMP(int N, int M)    //N为字典存量，M为目标的宽度
{
    int i = 0, j = 0;
    for(; i < N;)
    {
        if(a[i] == b[j])
        {
            if(j == M - 1)
                return i - (M - 1) + 1;
            i ++, j ++;
        }
        else
        {
            j = next[j];
            if(j == -1)
                i ++, j = 0;
        }
    }
    return -1;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int N, M;
        scanf("%d%d", &N, &M);
        for(int i = 0; i < N; i++)   scanf("%d", &a[i]);
        for(int i = 0; i < M; i ++)  scanf("%d", &b[i]);

        get_next(M);                      //一定要先将next数组初始化了
        int k = KMP(N, M);                //这个返回的满足条件的最小的地址
        printf("%d\n", k);
    }
}
