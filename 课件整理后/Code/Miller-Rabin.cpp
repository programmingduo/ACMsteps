/*
    随机判断一个数是否为素数
    32位内用前5个素数做基底，64位内用前8个 
    实在太卡试试7个 ,太卡的话，2，3拿出来判断 
*/
#include<iostream>
#include<cstdlib>
#define ll long long
using namespace std;

ll expmod(ll a,ll b,ll n)//a^b %m 注意可能要用long long时用long long 
{
    ll re=1,y=a%n;
    while(b){
        if (b%2)re=(re*y) %n;
        b>>=1,y=(y*y)%n;
    }
    return re;
}

bool randomisprim(ll n, int id) 
//判断n是否为素数，如果不是，那么将会有>1/2的概率检测出来 
//返回1，表示是素数，0表示不是。 
/*
        判断素数的写法 :
		int k=5;//32位内是5，64位用8 
		while(k -- && randomisprim(p, k));
		if (k == -1)cout<< p <<' ';
*/
{
    if (n == 2 || n == 3) return 1;
	
    ll jp[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    ll cn = 0, m = n-1, b = jp[id], k, temp;
	
    for(m = n-1; m%2 == 0; m /= 2, cn ++);
    
    if (b == n) return 1;
    
	k=expmod(b,m,n);
	if (k==1)return 1;
	
    for(int i = 0; i < cn; i++){
		if (k==n-1 || k==-1)return 1;
		k = (k*k)%n;
	}
	
    return 0;
}

ll pollard(ll n)
{
    
}

int main()
{
    ll n;
    while(cin >> n){
        int k = 8;
        while(k -- && randomisprim(i, n));
        if (k == -1) cout << "Prime" << endl;
            else{
                    ll tp = pollard(n);
                    cout << tp << endl;
                }
    }
    return 0;
}
