#include<cstdio>
#include<string.h>
#include<iostream>

using namespace std;

int main ()
{
    char a[60][60];
    int n, m, cha[4], out, ans, tempi, tempj;
    int in[4] = {0, 0, 1, 1};
    int jn[4] = {0, 1, 0, 1};
    while(~scanf("%d%d", &n, &m))
    {
        out = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j< m; j ++)
            cin>>a[i][j];
        for(int i = 0; i < n - 1; i ++)
        {
            for(int j = 0; j < m - 1; j ++)
            {
                memset(cha, 0, sizeof(cha));
                for(int k = 0; k < 4; k ++)
                {
                    tempi = i + in[k];
                    tempj = j + jn[k];
                    switch(a[tempi][tempj])
                    {
                        case 'f':
                            cha[0] ++;
                            break;
                        case 'a':
                            cha[1] ++;
                            break;
                        case 'c':
                            cha[2] ++;
                            break;
                        case 'e':
                            cha[3] ++;
                            break;
                    }
                    if(cha[0] && cha[1] && cha[2] && cha[3])
                        out ++;
                }
            }
        }
        printf("%d\n", out);
    }
    return 0;
}
