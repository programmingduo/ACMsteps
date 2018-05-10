/*
    1.�����ļӷ��ͳ˷�������Ҫע���һ���� row����Ϣ���������ֻ��һ�ָ��ӵ���Ϣ������û�д���
    �����Ҫʹ�õ�row��Ϣ����ô�������ʹ��֮ǰgetrow
    2. row���ŵ����е���Ϣ��row[i]��ʾ��i�д�������ʼ 
    row[0]��ȻΪ1��row[n]Ϊa.tn��������ʵû��row[n],����֮��������������Ϊ��дfor����ʱ�򷽱㣩
*/ 
#include <iostream>
using namespace std;

#define  maxn  10020   //ע�����ﲻҪ���磬��ʱfzu�ϳ�������˺ܶ�Ī������Ĵ���
#define  maxmatrix 111 //ҪתΪϡ�����ľ������߳� 
#define  mod 10000

struct node{
    int i, j, dt;
    node operator +(node &a);
    };
struct matrixtype{
    node data[maxn];
    int rb[maxn]; //rb��ʾ��r�е���ʼλ�� 
    int n, m, tn;
    };

node node::operator+(node &a)
{
    node b;
    b.i = a.i, b.j = a.j;
    b.dt = a.dt + dt;
    return b;
}

void fz(matrixtype &a, matrixtype &b)
{
    a.n = b.n;
    a.m = b.m;
    a.tn = b.tn;
    for(int i = 0; i < b.tn; i ++)
        a.data[i] = b.data[i];
}

void multiply(matrixtype &a, matrixtype &b, matrixtype &c)
{
    c.tn = 0, c.n = a.n,  c.m = b.m;
    for(int i = 0; i < a.n; i ++){
        if (a.rb[i] != a.rb[i + 1]){
            
            int row[maxn] = {0};
            for(int pa = a.rb[i]; pa < a.rb[i + 1]; pa ++){
                int j = a.data[pa].j;
                for(int pb = b.rb[j]; pb < b.rb[j + 1]; pb ++)
                    row[b.data[pb].j] += (a.data[pa].dt * b.data[pb].dt)%mod;
            }
            
            for(int k = 0; k < b.m; k ++)
                if (row[k]){
                    c.data[c.tn].i = i;
                    c.data[c.tn].j = k;
                    c.data[c.tn ++].dt = row[k]%mod;
                }
        }
    }
}

void getrow(matrixtype &a)
{
    int row[maxn] = {0};
    for(int i = 0; i < a.tn; i ++)
        row[a.data[i].i] ++;
    a.rb[0] = 0;
    for(int i = 1; i <= a.n; i ++)
        a.rb[i] = a.rb[i - 1] + row[i - 1];
}

void change(matrixtype &a, int b[][maxmatrix], int n, int m)//��ĳ������ת��Ϊϡ����� 
{
    a.n = n, a.m = m, a.tn = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++){
            if (b[i][j]){
                a.data[a.tn].i = i;
                a.data[a.tn].j = j;
                a.data[a.tn ++].dt = b[i][j];
            }
        }
    getrow(a);
} 

void write(matrixtype c)
{
        int k = 0;
        for(int i = 0; i < c.n; i ++){
            for(int j = 0; j < c.m; j ++){
                if (c.data[k].i == i && c.data[k].j == j){
                    cout << c.data[k++].dt << ' ';
                }else{
                        cout << 0 << ' ';
                     }
            }
            cout << endl;
        }
}


int temp[maxmatrix][maxmatrix];

matrixtype cm[2], sre[2];
void expmod(matrixtype &sm, int n)
{
    int cmup = 1, cmdown = 0, redown = 0, reup = 1;
    fz(cm[0], sm);
    int k = sm.n;
    
    sre[0].tn = k, sre[0].n = sre[0].m = k;
    for(int i = 0; i < sre[0].tn; i ++)
        sre[0].data[i].i = sre[0].data[i].j = i, sre[0].data[i].dt = 1;
    while(n){
        getrow(cm[cmdown]);
        if (n % 2){
            getrow(sre[redown]);
            multiply(sre[redown], cm[cmdown], sre[reup]);
            swap(reup, redown);
        }
        n >>= 1;
        multiply(cm[cmdown], cm[cmdown], cm[cmup]);
        swap(cmdown, cmup);
    }
    fz(sm, sre[redown]);
}

int a[maxmatrix], b[maxmatrix];

int main()
{
    int k, n;
    while(scanf("%d", &k), k!=0){
        for(int i = 0; i < k; i ++)
            scanf("%d", a+i);
        for(int i = 0; i < k; i ++)
            scanf("%d", b+i);
            
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i < k; i ++)
            temp[0][i] = b[i], temp[i+1][i] = 1;
        matrixtype sm;
        scanf("%d", &n);
        if (n < k){
            printf("%d\n", a[n]);
            continue;
        }else n -= k-1;
        
        change(sm, temp, k, k);
        
        expmod(sm, n);
        
        int ans = 0;
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i < sm.tn; i ++)
            temp[sm.data[i].i][sm.data[i].j] = sm.data[i].dt;
        for(int i = 0; i < k; i ++)
            ans += (temp[0][i]*a[k-1-i])%mod;    
        printf("%d\n", ans%mod);
    }
    return 0;
}
