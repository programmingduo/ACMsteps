#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

int n, a[15];
int pass[15][15];

void init()
{
    memset(pass, 0, sizeof(pass));
    pass[1][3] = 2;
    pass[3][1] = 2;
    pass[1][7] = 4;
    pass[7][1] = 4;
    pass[3][9] = 6;
    pass[9][3] = 6;
    pass[7][9] = 8;
    pass[9][7] = 8;
    pass[2][8] = pass[3][7] = pass[1][9] = pass[4][6] = pass[8][2] = pass[7][3] = pass[9][1] = pass[6][4] = 5;
}

bool judge()
{
    int temp;
    for(int i = 1; i < n; i ++)
    {
        if(temp = pass[a[i]][a[i - 1]])
        {
            for(int j = i + 1; j < n; j ++)
                if(a[j] == temp)
                return false;
            int flag = 0;
            for(int j = i - 2; j >= 0; j --)
            {
                if(a[j] == temp)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                return false;
        }
    }
    return true;
}

int main ()
{
    int T, len;
    scanf("%d", &T);
    init();
    while(T --)
    {
        len = 0;
        scanf("%d", &n);
        for(int i =0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }

        vector<vector<int> > ans;
        vector<int> tempv;
        sort(a, a + n);
        do
        {
            if(judge())
            {
                tempv.clear();
//                for(int i = 0; i < n; i ++)
//                    printf("%d ", a[i]);
//                printf("\n");
                for(int i = 0; i < n; i ++)
                {
                    tempv.push_back(a[i]);
                }
//                for(int i = 0; i < n; i ++)
//                    printf("%d ", tempv[i]);
//                printf("\n");
                ans.push_back(tempv);
                len ++;
            }
        }while(next_permutation(a, a + n));

        printf("%d\n", len);
        for(int i = 0; i < len; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(j)
                    printf(" %d", ans[i][j]);
                else
                    printf("%d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
