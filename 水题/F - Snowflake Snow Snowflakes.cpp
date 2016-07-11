#include<cstdio>
//���ڱ���ֻ��һ�����ݣ���˳�ʼ����������

const int mod = 999983;

struct node        //����Ľڵ�ṹ��
{
    int num[6];
    node* befor;
    node* next;
}ele[100005];

node* hashtable[1000000];    //��ϣ���飬��¼ÿһ����ϣ�����׵�ַ�������û��Ԫ��ָ��NULL

int gethash(int num[])
{
    int total = 0;
    for(int i = 0; i < 6; i ++)
    {
        total += (num[i]  % mod);
    }
    return total % mod;
}

bool compare(int num1[], int num2[])
{
    int flag = 1;
    for(int i = 0; i < 6; i ++)     //˳ʱ��Ĳ�ͬ���
    {
        flag = 1;
        for(int j = 0; j < 6; j ++)
        {
            if(num1[j] != num2[(j + i) % 6])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            return 1;
    }

    for(int i = 0; i < 6; i ++)           //��ʱ��Ĳ�ͬ���
    {
        flag = 1;
        for(int j = 0; j < 6; j ++)
        {
            if(num1[j] != num2[(i - j + 6) % 6])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            return 1;
    }
    return 0;
}

bool findinhash(int hashnum, int num[])         //������ϣ����ʱ��ʱ�Ѿ����˸�Ԫ��
{
    node* temp = hashtable[hashnum];
    while(temp != NULL)
    {
        if(compare(num, temp->num))
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void inserthash(int num[], int i)              //���ϣ���в���Ԫ��
{
    int temp = gethash(num);
    ele[i].befor = NULL;
    ele[i].next = hashtable[temp];
    if(hashtable[temp] != NULL)
        hashtable[temp]->befor = &ele[i];
    hashtable[temp] = &ele[i];
    for(int j = 0; j < 6; j ++)
    {
        ele[i].num[j] = num[j];
    }
}

int main ()
{
    int T, num[6];
    bool flag = 0;
    scanf("%d", &T);
    for(int i = 0; i < T; i ++)
    {
        for(int j = 0; j < 6; j ++)
            scanf("%d", &num[j]);
        if(flag == 1)
            continue;
        int temp = gethash(num);
        if(findinhash(temp, num))
        {
            flag = 1;
        }
        else
        {
            inserthash(num, i);
        }
    }
    if(flag)
        printf("Twin snowflakes found.\n");
    else
        printf("No two snowflakes are alike.\n");

    return 0;
}
