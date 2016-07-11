#include<cstdio>

int main ()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int num[1005];
    for(int i = 0; i < n; i ++)
        scanf("%d", &num[i]);

    for(int i = 0; i < m; i ++)
    {
        int a;
        scanf("%d", &a);
        int first = 0, last = n - 1, mid;

        while(last >= first)
        {
            mid = (first + last) / 2;
            //printf("mid = %d\n", mid);
            if(num[mid] == a)
            {
                //printf("1\n");
                first = mid;
                break;
            }
            else if(num[mid] < a)
            {
                //printf("2\n");
                first = mid + 1;
            }
            else
            {
                //printf("3\n");
                last = mid - 1;
            }
        }
        printf("%d\n", first);
    }
    return 0;
}
