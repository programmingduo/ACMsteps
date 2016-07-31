#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

bool visit[10000];
int p, a, b;

int main()
{
    //scanf("%d", &p);
    while(~scanf("%d", &p) && p){
        while(~scanf("%d", &a) && a){
            scanf("%d", &b);
            memset(visit, 0, sizeof visit);
            int tmp = 1;)
            bool flag = false;
            bool fail = false;
            int cnt = 1;
            while(1){
                tmp = ((tmp%p) * (a%p)) % p;
                if(tmp == b){
                    flag = true;
                    break;
                }
                if(visit[tmp]){
                    fail = true;
                    break;
                }
                visit[tmp] = true;
                cnt++;
            }
            if(fail){
                printf("0\n");
            }
            else if (flag){
                printf("%d\n", cnt);
            }
        }
    }
    return 0;
}
