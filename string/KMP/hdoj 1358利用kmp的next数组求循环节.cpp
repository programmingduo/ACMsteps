#include<cstdio>

char in[1000005];
int next[1000005];
int N;

void get(void)
{
    for(int i = 2; i <= N; i ++)
    {
        int j = next[i - 1];
        while(j && in[j] != in[i - 1])
            j = next[j];
        next[i] = in[i - 1] == in[j] ? j + 1: 0;
    }
}

void work(void)
{
    for(int i = 1; i <= N; i ++)
        if(i % (i - next[i]) == 0 && i / (i - next[i]) > 1)
            printf("%d %d\n", i, i / (i - next[i]));
}

int main ()
{
    int a = 1;
    while(scanf("%d", &N), N != 0)
    {
        scanf("%s", in);
        printf("Test case #%d\n", a ++);
        get();
        work();
        printf("\n");
    }
    return 0;
}
