#include<cstdio>
#include<algorithm>
using namespace std;

int a[10000], b[2000], c[2000];
int main ()
{
    int T, n, m;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &m);
        int temp = m;
        for(int i = 0; i < m; i ++)
            scanf("%d", &c[i]);
        for(int i = 1; i < n; i ++)
        {
            sort(c, c + m);
            for(int i = 0; i < m; i ++)
                scanf("%d", &b[i]);
            for(int i = 0; i < m; i ++)
                a[i] = b[0] + c[i];
            make_heap(a, a + m);
            for(int i = 1; i < m; i ++)
            {
                for(int j = 0; j < m; j ++)
                {
                    if(b[i] + c[j] > a[0])
                        break;
                    pop_heap(a, a + m);
                    a[m - 1] = b[i] + c[j];
                    push_heap(a, a + m);
                }
            }
            for(int i = 0; i < m; i ++)
                c[i] = a[i];
        }
        sort(c, c + m);
        for(int i = 0; i < m; i ++)
        {
            if(i)
                printf(" %d", c[i]);
            else
                printf("%d", c[i]);
        }
        printf("\n");
    }
    return 0;
}
