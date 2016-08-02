#include<cstdio>
#include<queue>
using namespace std;

priority_queue<long long , vector<long long >, greater<long long > > q;

int main ()
{
    long long a, b, sum;
    int n;
    while(~scanf("%d", &n))
    {
        sum = 0;
        while(!q.empty())
            q.pop();
        for(int i = 0; i < n; i ++)
        {
            scanf("%lld", &a);
            q.push(a);
        }
//        while(!q.empty())
//        {
//            a = q.top();
//            q.pop();
//            printf("%d ", a);
//        }
        while(q.size() != 1)
        {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            sum += a + b;
            q.push(a + b);
        }
        printf("%lld\n", sum);
    }
}
