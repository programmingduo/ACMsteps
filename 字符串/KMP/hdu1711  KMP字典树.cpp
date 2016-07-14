#include<cstdio>

using namespace std;

int a[1000005], b[10005];   //a���ֵ䣬b��Ŀ������
int next[10005];            // next��¼��b��ÿһ���ַ�ǰ�뿪ͷ�ж��ٸ���һ����

void get_next(int M)        //��ʼ��Ŀ�꣬MΪĿ��ĳ���
{
    int j = 0, k = -1;
    next[0] = -1;
    while(j < M)
    {
        if(k == -1 || b[j] == b[k])
            next[++j] = ++k;
        else
            k = next[k];
    }
}

int KMP(int N, int M)    //NΪ�ֵ������MΪĿ��Ŀ��
{
    int i = 0, j = 0;
    for(; i < N;)
    {
        if(a[i] == b[j])
        {
            if(j == M - 1)
                return i - (M - 1) + 1;
            i ++, j ++;
        }
        else
        {
            j = next[j];
            if(j == -1)
                i ++, j = 0;
        }
    }
    return -1;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int N, M;
        scanf("%d%d", &N, &M);
        for(int i = 0; i < N; i++)   scanf("%d", &a[i]);
        for(int i = 0; i < M; i ++)  scanf("%d", &b[i]);

        get_next(M);                      //һ��Ҫ�Ƚ�next�����ʼ����
        int k = KMP(N, M);                //������ص�������������С�ĵ�ַ
        printf("%d\n", k);
    }
}
