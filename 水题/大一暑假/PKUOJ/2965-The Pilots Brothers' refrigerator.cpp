#include<iostream>
#include<cstdio>

using namespace std;
char switchs[16];

bool isOver()
{
    for(int i = 0; i < 16; i ++)
        if(switchs[i] == '+')
        return false;
    return true;
}

void swap(int a)
{
    if(switchs[a] == '-')
        switchs[a] = '+';
    else
        switchs[a] = '-';
}

void turn(int element)
{
    int column, row;
    column = element % 4;
    row = element / 4;
    for(int i = 0; i < 4; i ++)
    {
        swap(i * 4 + column);
        swap(i + row * 4);
    }
    swap(element);
}

bool combine(int numbers, int* result, int start = 0, int current = 0)
{
    for(int i = start; i <= 16 - numbers; i ++)
    {
        result[current] = i;
        turn(i);
        if(numbers == 1)
            if(isOver())
            {
                return 1;
            }
        if(numbers != 1)
            if(combine(numbers - 1, result, i + 1, current + 1))
                return 1;
        turn(i);
    }
    return 0;
}

void print(int element)
{
    printf("%d %d\n", element/4+1, element%4+1);
}

int main ()
{
    int result[16];
    for(int i = 0; i < 16; i ++)
        cin>> switchs[i];
    for(int i = 1; i <= 16; i ++)
    {
        if(combine(i, result))
        {
            printf("%d\n", i);
            for(int j = 0; j < i; j ++)
                print(result[j]);
            return 0;
        }
    }
    return 0;
}
