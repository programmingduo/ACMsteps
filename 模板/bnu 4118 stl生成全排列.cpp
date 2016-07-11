#include<cstdio>
#include<algorithm>

int a[10];

int main ()
{
    int n;
    for(int i = 1; i <= 9; i ++)
    {
        a[i - 1] = i;
    }
    scanf("%d", &n);
    do
    {
        for(int i = 0; i < n; i ++)
            printf("%d", a[i]);
        printf("\n");
    }while(std::next_permutation(a, a + n));
    return 0;
}
