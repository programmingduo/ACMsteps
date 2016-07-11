#include<stack>
#include<cstdio>
#include<iostream>

using namespace std;

bool ans, boo[5];
string a;
stack<int> num;


void check(int& pos)
{
    //�ȷ�posλ��bool����operator
    if(a[pos] >= 'p')
        num.push(boo[a[pos] - 'p']);
    else
    {
        //������һԪ��������Ƕ�Ԫ�����
        if(a[pos] == 'N')
        {
            int temp = num.top();
            num.pop();
            num.push(!temp);
        }
        else
        {
            int x = num.top();
            num.pop();
            int y = num.top();
            num.pop();

            switch(a[pos])
            {
            case 'A':
                num.push(x | y);
                break;
            case 'K':
                num.push(x & y);
                break;
            case 'C':
                num.push(x | !y);
                break;
            case 'E':
                num.push(x == y);
                break;
            }
        }
    }
}

int main ()
{
    while(cin>> a)
    {
        if(a[0] == '0')
            break;
        ans = 1;
        for(int i = 0; i < 31; i ++)
        {
            //��ʵ��һ����ϣ����char��int��һ��ӳ��
            boo[0] = i & 1;
            boo[1] = i & 1 << 1;
            boo[2] = i & 1 << 2;
            boo[3] = i & 1 << 3;
            boo[4] = i & 1 << 4;

            for(int j = a.length() - 1; j >= 0; j --)
            {
                check(j);
            }
            ans = num.top();
            num.pop();
            if(ans == 0)
                break;
        }
        if(ans)
            printf("tautology\n");
        else
            printf("not\n");
    }
}
