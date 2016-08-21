#include<cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char c[205][205];
int tc[205][205];

int pos[4][2][2] = {{0, -1, 1, 0}, {-1, 0, 0, -1}, {-1, 0, 0, 1}, {0, 1, 1, 0}};
int vis[16], x[16], y[16];
int main ()
{
    //for(int i = 0; i < 4; i ++){
    //    for(int j = 0; j < 2; j ++){
    //        cout << pos[i][j][0] << " " << pos[i][j][1] << endl;
    //    }
   // }
    int n, m, total;
    while(~scanf("%d %d", &n, &m) && (n != 0 || m != 0))
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", c[i]);
        }
        memset(tc, -1, sizeof(tc));
        total = 0;
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(c[i][j] == '.')
                {
                    tc[i][j] = total;
                    x[total] = i;
                    y[total] = j;
                    total ++;
                }
            }
        }
        if(total == 0){
            printf("0\n");
            continue;
        }
        int ct = 0, ca, ans = 100000000;
        bool flag;
        for(int i = 0; i < total; i ++){
            for(int j = 0; j < 4; j ++){
                for(int k = 0; k < (1 << total); k ++){
                    flag = true;
                    ct = 0, ca = 0;
                    memset(vis, 0, sizeof(vis));
                    for(int l = 0; l < total && flag; l ++){
                        if(k & (1 << l)){
                            ca ++;
                            if(!vis[l]){
                                vis[l] = 1;
                                ct ++;
                            }
                            int x1 = 0, y1 = 1, x2 = -1, y2 = 0;
                            if(l == i){
                                x1 = pos[j][0][0];
                                y1 = pos[j][0][1];
                                x2 = pos[j][1][0];
                                y2 = pos[j][1][1];
                            }
                            if(x[l] + x1 >= 0 && x[l] + x1 < n && y[l] + y1 >= 0 && y[l] + y1 < m){
                                int tmp = tc[x[l]+x1][y[l]+y1];
                                if( tmp == -1)
                                    flag = false;
                                else{
                                    if(!vis[tmp]){
                                        vis[tmp] = 1;
                                        ct ++;
                                    }
                                }
                            }
                            if(x[l] + x2 >= 0 && x[l] + x2 < n && y[l] + y2 >= 0 && y[l] + y2 < m){
                                int tmp = tc[x[l]+x2][y[l]+y2];
                                if( tmp == -1)
                                    flag = false;
                                else{
                                    if(!vis[tmp]){
                                        vis[tmp] = 1;
                                        ct ++;
                                    }
                                }
                            }
                        }
                    }
                    if(flag && ct == total){
                        ans = min(ans, ca);
                    }
                }
            }
        }
        if(ans == 100000000)
            ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
