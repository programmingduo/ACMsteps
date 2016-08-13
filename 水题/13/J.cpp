#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define maxn 100010
ll c[maxn];
ll cnt[maxn];
ll record[maxn];
int n, m, t;
ll x, y;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(record, 0, sizeof record);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++){
            scanf("%I64d", &c[i]);
        }
        for (int i = 0; i < m; i++){
            scanf("%I64d%I64d", &x, &y);
            x--;
            cnt[x] += y;
        }
        ll res = 0;
        for (int i = 0; i < n; i++){
            cnt[i] += res;
            if(cnt[i] > c[i]){
                res = cnt[i] - c[i];
                record[i] = c[i];
            }
            else{
                res = 0;
                record[i] = cnt[i];
            }
        }
        printf("%I64d\n", res);
        for (int i = 0; i < n; i++){
            printf("%I64d", record[i]);
            if(i != n-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
