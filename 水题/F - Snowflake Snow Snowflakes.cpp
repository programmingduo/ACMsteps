#include<cstdio>
//由于本题只有一组数据，因此初始化不够严密

const int mod = 999983;

struct node        //链表的节点结构体
{
    int num[6];
    node* befor;
    node* next;
}ele[100005];

node* hashtable[1000000];    //哈希数组，记录每一个哈希数的首地址。如果还没有元素指向NULL

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
    for(int i = 0; i < 6; i ++)     //顺时针的不同起点
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

    for(int i = 0; i < 6; i ++)           //逆时针的不同起点
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

bool findinhash(int hashnum, int num[])         //看看哈希表中时不时已经有了该元素
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

void inserthash(int num[], int i)              //向哈希表中插入元素
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
