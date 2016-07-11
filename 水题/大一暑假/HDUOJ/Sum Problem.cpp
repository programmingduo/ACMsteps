#include<cstdio>

using namespace std;

int main()
{
    int N;
    while(~scanf("%d", &N))
    {
        int sum = 0;
        for(int i = 1; i <= N; i ++)
            sum += i;

        printf("%d\n\n", sum);
    }
}
