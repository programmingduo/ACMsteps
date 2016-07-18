#include<cstdio>
#include<cstdlib>

struct treap
{
    treap *left, *right;
    int val, pri;
    int size;
    treap (int vv)
    {
        left = right = NULL;
        pri = rand();
        val = vv;
    }
}*root;

void print(treap *p)
{
    if(!p)
        return;
    print(p->left);
    printf("%d ", p->val);
    print(p->right);
}

int lsize(treap *p)
{
    return p->left ? p->left->size : 0;
}

int rsize(treap *p)
{
    return p->right ? p->right->size : 0;
}

//传参数的时候一定记得&
//左旋。
void l_rotate(treap *&p)
{
    treap *temp = p->right;
    p->right = temp->left;
    temp->left = p;
    temp->size = p->size;
    p->size = lsize(p) + rsize(p) + 1;
    p = temp;
}

void r_rotate(treap *&p)
{
    treap *temp = p->left;
    p->left = temp->right;
    temp->right = p;
    temp->size = p->size;
    p->size = lsize(p) + rsize(p) + 1;
    p = temp;
}

void insert(treap *&p, int val)
{
    if(!p)
    {
        p = new treap(val);
        p->size = 1;
    }
    else if(val <= p->val)
    {
        p->size ++;
        insert(p->left, val);
        if(p->left->pri < p->pri)
            r_rotate(p);
    }
    else
    {
        p->size ++;
        insert(p->right, val);
        if(p->right->pri < p->pri)
            l_rotate(p);
    }
}

int find(int k, treap *p)
{
    int temp = lsize(p);
    if(k == temp + 1)
        return p->val;
    else if(k <= temp)
        return find(k, p->left);
    else return find(k - temp - 1, p->right);
}



int main ()
{
    int m, n, num[30005];
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i ++)
        scanf("%d", &num[i]);
    int temp = 1, len, ans;
    root = NULL;

    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &len);
        for(; temp <= len; temp ++)
        {
            insert(root, num[temp]);
        }
        ans = find(i, root);
        printf("%d\n", ans);
    }
    return 0;
}
