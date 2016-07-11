#include<cstdio>
#include<algorithm>

using namespace std;

int main ()
{
    int N, M, v[11], ans = 0;
    scanf("%d%d", &N, &M);
    for(int i = 0; i <= N; i ++)
    {
        v[i] = i + 1;
    }

    do
    {
        int l = 0;
        for(int i = 0; i < N; i ++)
        {
            l = 0;
            for(int j = i + 1; j < N; j ++)
            {
                if(v[j] < v[i])
                    l ++;
            }
            if(l > M)
                break;
        }
        if(l <= M)
        {
            for(int i = 0; i < N; i ++)
                printf("%d", v[i]);
            printf("\n");
            ans ++;
        }
    }while(next_permutation(v, v + N));

    printf("%d\n", ans);
    return 0;
}
