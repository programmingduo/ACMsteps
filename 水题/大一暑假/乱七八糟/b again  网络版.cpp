#include <iostream>
using namespace std;

int map[501][501];
bool visit[10002];
int match[10002];
int n;

bool path(int start)
{
    int i;

    for ( i = 1; i <= n; i++ )
    {
        if ( map[start][i] && !visit[i] ){
            visit[i] = true;
            if ( match[i] == -1 || path(match[i]) )
            {
                match[i] = start;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int k,i;
    int x,y;
    int result;

    memset(match,-1,sizeof(match));
    memset(map,0,sizeof(map));
    cin >> n >> k;
    for ( i = 1; i <= k; i++ )
    {
        cin >> x >> y;
        map[x][y] = 1;
    }
    result = 0;
    for ( i = 1; i <= n; i++ )
    {
        memset(visit,false,sizeof(visit));
        if (path(i))
            result++;
    }
    cout << result << endl;
    return 0;
}
