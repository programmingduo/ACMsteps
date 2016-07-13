#include<cstdio>
#include<cstring>

char s[105];

struct node
{
    node* next[10];
    int val;
    int tail;
    node()
    {
        tail = 0;
        val = 0;
        memset(next, 0, sizeof(next));
    }
}*root;


//OK
char * standard(char *s)
{
    char *c;
    c = new char[10];
    for(int i = 0, len = 0; s[i]; i ++)
    {
        if(s[i] == '-' || s[i] == 'Q' || s[i] == 'Z')
            continue;
        if(s[i] >= '0' && s[i] <= '9')
            c[len ++] = s[i];
        else
        {
            switch(s[i])
            {
            case 'A': case 'B': case 'C':
                c[len ++] = '2';
                break;
            case 'D': case 'E': case 'F':
                c[len ++] = '3';
                break;
            case 'G': case 'H': case 'I':
                c[len ++] = '4';
                break;
            case 'J': case 'K': case 'L':
                c[len ++] = '5';
                break;
            case 'M': case 'N': case 'O':
                c[len ++] = '6';
                break;
            case 'P': case 'R': case 'S':
                c[len ++] = '7';
                break;
            case 'T': case 'U': case 'V':
                c[len ++] = '8';
                break;
            case 'W': case 'X': case 'Y':
                c[len ++] = '9';
                break;
            default:
                continue;
            }
        }
    }
    c[7] = 0;
    return c;
}



void insert(char *s)
{
//    printf("%s ", s);
//    printf("%d", s[0]);
    node *p = root;
    int t = 0;
    for(int i = 0; i < 7; i ++)
    {
//        printf("%c", s[i]);
        t = s[i] - '0';
        if(!p->next[t])
            p->next[t] = new node();
        p = p->next[t];
        p->val ++;
    }
//    printf("\n");
    p->tail ++;
}

int index, flag;
char ans[10];

void search(node *t)
{
//    printf("%d ", index);
    if(t->val < 2)
        return ;
    if(index == 7)
    {

        if(t->tail < 2)
            return ;
        flag = 1;
        for(int i = 0; i < 3; i ++)
            printf("%c", ans[i]);
        printf("-");
        for(int i = 3; i < 7; i ++)
            printf("%c", ans[i]);
        printf(" %d\n", t->val);
        return ;
    }
    for(int i = 0; i < 10; i ++)
    {
        if(!t->next[i])
            continue;
        ans[index ++] = '0' + i;
        search(t->next[i]);
        index --;
    }
}

int main ()
{
    int n;
    char *c;
    flag = 0;
    root = new node();
    scanf("%d", &n);
    root-> val = n;
    while(n --)
    {
        scanf("%s", s);
        c = standard(s);
        insert(c);
    }
    index = 0;
    search(root);
    if(flag == 0)
        printf("No duplicates.\n");
    return 0;
}
