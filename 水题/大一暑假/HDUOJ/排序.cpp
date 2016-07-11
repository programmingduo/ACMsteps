#include<iostream>
#include<string>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

void heapSort(int a[], int size)
{
    int n = size / 2 - 1;
    for(int i = n; i >= 0; i --)
    {
        int k = i;
        for(int j = 2 * k + 1; j < size; j = j * 2 + 1)
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

    for(int i = 0; i < size - 1; i ++)
    {
        n = size - i - 1;
        int k = 0;
        for(int j = 1; j < n; j = j * 2 + 1)
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

int main()
{
    string number;
    while(cin>> number)
    {
        //cinvert the string to numbers
        int numbers[10005] = {0};
        int cases = 0;
        for(int i = 0; i < number.length(); i ++)
        {
            if(i == 0 && number[0] == '5')
            {
                for(int j = 1; number[j] == '5'; j ++)
                    i = j;
                continue;
            }
            if(i < number.length() - 1 && number[i] == '5' && number[i+ 1] == '5'
               || number[i] == '5' && i == number.length() - 1)
                continue;

            if(number[i] == '5')
            {
                cases ++;
                continue;
            }
            numbers[cases] = numbers[cases] * 10 + number[i] - '0';
        }

        //sort
        heapSort(numbers, cases + 1);

        //print
        cout<< numbers[0];
        for(int i = 1; i <= cases; i ++)
            cout<< " "<< numbers[i];
        cout<< endl;
    }
    return 0;
}
