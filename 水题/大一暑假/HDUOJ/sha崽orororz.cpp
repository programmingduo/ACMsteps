#include<iostream>
#include<algorithm>
using namespace std;

void swap(long long& a, long long& b)
{
    long long temp = a;
    a = b;
    b = temp;
    return;
}

void heapSort(long long a[], long long size)
{
    long long n = size / 2 - 1;
    for(long long i = n; i >= 0; i --)
    {
        long long k = i;
        for(long long j = 2 * k + 1; j < size; j = j * 2 + 1)
        {
            if(j + 1 < size && a[j] < a[j + 1])
                j ++;
            if(a[k] < a[j])
            {
                swap(a[k], a[j]);
                k = j;
            }
            else
                break;
        }
    }
    swap(a[0], a[size - 1]);

    for(long long i = 0; i < size - 1; i ++)
    {
        n = size - i - 1;
        long long k = 0;
        for(long long j = 1; j < n; j = j * 2 + 1)
        {
            if(j + 1 < n && a[j] < a[j + 1])
                j ++;
            if(a[k] < a[j])
            {
                swap(a[k], a[j]);
                k = j;
                continue;
            }
            else
                break;
        }
        swap(a[0], a[n - 1]);
    }
}

int main ()
{
    long long N;
    while(cin>> N)
    {
        long long a[10005];
        for(long long  i = 0; i < N; i ++)
            cin>> a[i];
        heapSort(a, N);
        bool isCout = false;
        long long first = 0, last = N - 1;
        while(first != last)
        {
            if(isCout)
            {
                cout<< a[first]<< " ";
                first ++;
                isCout = false;
            }
            else
            {
                cout<< a[last]<< " ";
                last --;
                isCout = true;
            }
        }
        cout<< a[first]<< endl;
    }
      return 0;
}
