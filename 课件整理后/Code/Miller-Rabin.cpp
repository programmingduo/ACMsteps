/*
    ����ж�һ�����Ƿ�Ϊ����
    32λ����ǰ5�����������ף�64λ����ǰ8�� 
    ʵ��̫������7�� ,̫���Ļ���2��3�ó����ж� 
*/
#include<iostream>
#include<cstdlib>
#define ll long long
using namespace std;

ll expmod(ll a,ll b,ll n)//a^b %m ע�����Ҫ��long longʱ��long long 
{
    ll re=1,y=a%n;
    while(b){
        if (b%2)re=(re*y) %n;
        b>>=1,y=(y*y)%n;
    }
    return re;
}

bool randomisprim(ll n, int id) 
//�ж�n�Ƿ�Ϊ������������ǣ���ô������>1/2�ĸ��ʼ����� 
//����1����ʾ��������0��ʾ���ǡ� 
/*
        �ж�������д�� :
		int k=5;//32λ����5��64λ��8 
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
