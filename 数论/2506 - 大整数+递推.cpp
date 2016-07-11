#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int Base = 1000000000;
const int Capacity = 100;

struct BigInt
{
    int Len;
    int Data[Capacity];
    BigInt() : Len(0) {}

    BigInt(const BigInt &V) : Len(V.Len)
    {
        memcpy(Data, V.Data, Len * sizeof(*Data));
    }

    BigInt(int V) : Len(0)
    {
        for(; V > 0; V /= Base)
            Data[Len ++] = V % Base;
    }

    BigInt &operator= (const BigInt &V)
    {
        Len = V.Len;
        memcpy(Data, V.Data, Len * sizeof(*Data));
        return *this;
    }

    int &operator[](int Index)
    {
        return Data[Index];
    }

    int operator[](int Index)   const
    {
        return Data[Index];
    }
};

BigInt operator+ (const BigInt &A, const BigInt &B)
{
    int i, Carry = 0;
    BigInt R;
    for(i = 0; i < A.Len || i < B.Len || Carry > 0; i ++)
    {
        if(i < A.Len) Carry += A[i];
        if(i < B.Len) Carry += B[i];
        R[i] = Carry % Base;
        Carry /= Base;
    }
    R.Len = i;
    return R;
}

BigInt operator* (const BigInt &A, const int &B)
{
    int i;
    long long Carry = 0;
    BigInt R;
    for(i = 0; i < A.Len || Carry > 0; i ++)
    {
        if(i < A.Len) Carry += A[i] * B;
        R[i] = Carry % Base;
        Carry /= Base;
    }
    R.Len = i;
    return R;
}

ostream &operator<< (ostream &out, const BigInt &V)
{
    int i;
    out<< (V.Len == 0? 0 : V[V.Len - 1]);
    for(int i = V.Len - 2; i >= 0; i --)
    {
        for(int j = Base /10; j > 0; j /= 10)
        {
            out<< V[i] / j % 10;
        }
    }
    return out;
}


int main ()
{
    BigInt ans[300];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;
    for(int i = 3; i < 255; i ++)
        ans[i] = ans[i - 1] + ans[i - 2] * 2;
    int num;
    while(~scanf("%d", &num))
    {
        cout<< ans[num]<< endl;
    }
    return 0;
}
