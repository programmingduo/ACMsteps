#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int t, n;
const int N = 100;
int uN, vN;                      //uN, vN为左右独立点集的数量
int linker[N];
bool used[N];

bool dfs(int u,char g[][N]){                  //从左边开始找增广路径
    for(int v = 1;v <= vN;v++)
      if(g[u][v]&&!used[v]){
          used[v] = true;
          if(linker[v] == -1||dfs(linker[v], g)){//找增广路，反向
              linker[v] = u;
              return true;
          }
      }
    return false;
}

int MaxMatch(char g[][N]){
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for(int u = 1;u <= uN;u++){
        memset(used, 0, sizeof(used));
        if(dfs(u, g))
            {
                res++;
                cout<< "in match "<< u<< endl;
            }
    }
    return res;
}

int main()
{
    char mapR[100][100];
    char mapB[100][100];
    char map0[55][55];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        uN = vN = n * 2 - 1;
        memset(mapR, '\0', sizeof(mapR));
        memset(mapB, '\0', sizeof(mapB));
        for (int i = 1; i <= n; i++){
            scanf("%s", map0[i] + 1);
        }
        int row, colume;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                colume = i + j - 1;
                row = n - (j - i);
                if(map0[i][j] == 'R' || map0[i][j] == 'G'){
                    mapR[row][colume] = 'R';
                }
                if(map0[i][j] == 'B' || map0[i][j] == 'G'){
                    mapB[row][colume] = 'B';
                }
            }
        }

//        cout << endl;
//        for (int i = 1; i <= n; i++){
//            for (int j = 1; j <= n; j++){
//                cout << map0[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
//        for (int i = 1; i <= 2 * n - 1; i++){
//            for (int j = 1; j <= 2 * n - 1; j++){
//                cout << mapR[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
//        for (int i = 1; i <= 2 * n - 1; i++){
//            for (int j = 1; j <= 2 * n - 1; j++){
//                cout << mapB[i][j];
//            }
//            cout << endl;
//        }

        int a = MaxMatch(mapB);
        int b = MaxMatch(mapR);
        cout<< (int )mapB[1][1];
        cout<< " A = "<< a<< endl;
        cout<< "b = "<< b<< endl;
        int ans = a + b;
        cout<< ans<< endl;
    }
    return 0;
}
