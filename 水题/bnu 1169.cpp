#include<cstdio>

int findmax(int num[][105], int j, int N)
{
    int ans = -10000000, temp = 0;
    for(int i = 0; i < N; i ++)
    {
        temp += num[j][i];
        ans = ans > temp ? ans : temp;
        if(temp < 0)
            temp = 0;
    }
    return ans;
}

int main ()
{
    int N, num[105][105], temp = 0, ans = -100000000;
    scanf("%d", &N);
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            scanf("%d", &num[i][j]);
        }
    }

    for(int i = 0; i < N; i ++)
    {
        temp = findmax(num, i, N);
        ans = ans > temp? ans: temp;
        for(int j = i + 1; j < N; j ++)
        {
            for(int k = 0; k < N; k ++)
            {
                num[i][k] += num[j][k];
            }
            temp = findmax(num, i, N);
            ans = ans > temp ? ans : temp;
        }
    }
    printf("%d\n", ans);

    return 0;
}
