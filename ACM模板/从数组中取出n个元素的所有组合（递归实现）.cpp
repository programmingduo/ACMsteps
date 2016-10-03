#include<cstdio>

using namespace std;

void combine_increase(const int *numbers, int *result, const int arrysize,const int elements,
                       int current = 0, int start = 0)
{
    for(int i = start; i <= arrysize - elements + current; i ++)
    {
        result[current] = i;
        if(elements - current - 1)
        {
            combine_increase(numbers, result, arrysize, elements, current + 1, i + 1);
        }
        else
        {
            for(int j = current; j >= 0; j --)
            {
                printf("%d\t", numbers[result[current - j]]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int numbers[] = {0, 1, 2, 3, 4, 5};
    int elements = 3;
    int *result = new int[3];
    combine_increase(numbers, result, 6, elements);
    return 0;
}
