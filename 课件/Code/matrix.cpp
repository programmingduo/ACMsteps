/*
    1.疏矩阵的加法和乘法，必须要注意的一点是 row的信息，由于这个只是一种附加的信息。所以没有处理
    如果你要使用到row信息，那么你必须在使用之前getrow
    2. row所放的是列的信息。row[i]表示第i行从哪里起始 
    row[0]必然为1，row[n]为a.tn（但是其实没有row[n],我们之所以这样做，是为了写for语句等时候方便）
*/ 
#include <iostream>
using namespace std;

#define  maxn  10020   //注意这里不要超界，当时fzu上超界出现了很多莫名其妙的错误。
#define  maxmatrix 111 //要转为稀疏矩阵的矩阵最大边长 
#define  mod 10000

struct node{
    int i, j, dt;
    node operator +(node &a);
    };
struct matrixtype{
    node data[maxn];
    int rb[maxn]; //rb表示第r行的起始位置 
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

void change(matrixtype &a, int b[][maxmatrix], int n, int m)//将某个矩阵转化为稀疏矩阵 
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
