#include<cstdio>
#include<cmath>
#include<map>

using namespace std;

double a[100005], b[100005];
map<double, int> m;
int main ()
{
    int T, n;
    double total;
    scanf("%d", &T);
    while(T --)
    {
        m.clear();
//        map<double, int>::iterator it = m.begin();
//        while(it != m.end())
//        {
//            it->second = 0;
//            it++;
//        }
        scanf("%d %lf", &n, &total);
        for(int i = 0; i < n; i ++)
        {
            scanf("%lf %lf", &a[i], &b[i]);
        }
        int flag = 0;
        for(int i = 0; i < n && !flag; i ++)
        {
            for(int j = i + 1; j < n && !flag; j ++)
            {
                double dis = abs(a[i] - a[j]) + abs(b[i] - b[j]);
                m[dis] ++;
                if(m[dis] >= 2)
                    flag = 1;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
