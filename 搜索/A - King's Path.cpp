#include<cstdio>
#include<map>
#include<deque>
using namespace std;

map<pair<int, int>, int> square;
deque<pair<int, int> > bfs;
int x[] = {-1, 0, 1}, y[] = {-1, 0, 1};

int main ()
{
    int x0, y0, x1, y1, n;
    scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &n);
    while(n --)
    {
        int r, a, b;
        scanf("%d%d%d", &r, &a, &b);
        for(int i = a; i <= b; i ++)
            square[make_pair(r, i)] = -1;
    }

    square[make_pair(x0, y0)] = 0;
    bfs.push_back(make_pair(x0, y0));
    int xx, yy, tempx, tempy;
    while(!bfs.empty())
    {
        xx = bfs.front().first;
        yy = bfs.front().second;
        bfs.pop_front();
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j ++)
            {
                tempx = xx + x[i];
                tempy = yy + y[j];
                if(square[make_pair(tempx, tempy)] == -1)
                {
                    square[make_pair(tempx, tempy)] = square[make_pair(xx, yy)] + 1;
                    bfs.push_back(make_pair(tempx, tempy));
                }
            }
    }
    printf("%d\n", square[make_pair(x1, y1)]);

    return 0;
}
