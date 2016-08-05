#include<cstdio>
#include<string.h>

char in[1000005];
int next[1000005], N;

void getNext()
{
    next[0] = next[1] = 0;
    for(int i = 2; i <= N; i ++)
    {
        int j = next[i - 1];
        while(j && in[j] != in[i - 1])
            j = next[j];
        next[i] = in[i - 1] == in[j] ? j + 1: 0;
    }
}

int work()
{
    getNext();
//    printf("1234");
    int j = next[N];
    while(j && N % (N - j))
        j = next[j];
    if(j == 0)
        return 1;
    return N / (N - j);
}

int main ()
{
    while(~scanf("%s", in))
    {
        if(in[0] == '.')
            break;
        N = strlen(in);
        printf("%d\n", work());
    }
    return 0;
}
