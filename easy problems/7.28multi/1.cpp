#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5+7;
const int mod = 1e9+7;
typedef long long ll;
int Next[N];
char a[N], b[N];
int n, m, T, len, lenb;
vector<int> sto;
int yunhao[N];
void getNext(){
	int j = 0, k = -1;
	Next[0] = -1;
	while(b[j] != '\0'){
		while(k != -1 && b[j] != b[k])
			k = Next[k];
		if(b[++j] == b[++k])
			Next[j] = Next[k];
		else
			Next[j] = k;
	}
}

void kmp(){
	//ans.clear();
	getNext();
	int ans = 0, i = 0, j = 0;
	while(a[i] != '\0'){
		while(j != -1 && a[i] != b[j])
			j = Next[j];
		i++;
		j++;
		if(j != -1 && b[j] == '\0'){
			sto.push_back(i - j);
			i = i - j + 1;
			j = 0;
		}
	}
}

long long cal(int i, int j)
{
    printf("%d %d\n", i, j);
    if(i == j)
        return 2;
    long long re = 0;
    int k = i + 1;
    for(int k = i + 1; k <= j; k ++)
        if(sto[k]-sto[i] > lenb)
        break;
    if(k > j)
        return (1 + cal(i+1, j)) % mod;
    else
        return (2*cal(k,j) + cal(i+1, j)) % mod;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --){
		sto.clear();
		scanf("%s%s", a, b);
		kmp();
//		if(sto.size() == 0){
//			puts("1");
//			continue;
//		}

		int total = sto.size();
		int j;
		lenb = strlen(b);
		ll ans = 1;
		for(int i = 0; i < total; i ++)
		{
            printf("%d ", sto[i]);
		}
		for(int i = 0; i < total; i ++)
		{
            for(j = i + 1; j < total; j ++)
            {
                if(sto[j] - sto[j - 1] > lenb)
                    break;
            }

            ans *= cal(i, j - 1);
            ans %= mod;
		}

		printf("%lld\n", ans);
	}
}
