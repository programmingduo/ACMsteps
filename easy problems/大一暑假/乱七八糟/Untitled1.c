#include<iostream>

using namespace std;

int &getfather(int father[], int road);

int main ()
{
    int M, N;  //M towns   N road
    while(scanf("%d", &M) && M != 0)
    {
        scanf("%d", &N);
        int *rodea, *roadb;
        roada = new int [N];
        roadb = new int [N];
        for(int i = 0; i < N; i ++)
        {
            scanf("%d, %d", &roada[N], &roadb[N]);
            if(roada[N] > roadb[N])
                swap(raoda[N], roadb[N]);
        }
        int father[1000] = {0}, fathers = 0;
        for(int i = 0; i < N; i ++)
        {
            if(!father[roada[i]] && !father[roadb[i]])
            {
                fathers ++;
                father[roada[i]] = raoda[i];
                father[roadb[i]] = roada[i];
            }
            else if(!father[roada[i]] && father[roadb]])
            {
                father[roada[i]] = father[roadb[i]];
            }
            else if(father[roada[i]] && !father[roadb]])
            {
                father[roadb[i]] = father[roada[i]];
            }
            else if(father[roada[i]] && father[roadb]])
            {
                if(getfather(roada[i]) != getfather(roadb[i]))
                {
                    fathers --;
                    getfather(father, roada[i]) = getfather(father, roadb[i]);
                }
            }
        }
        int ans = fathers;
        for(int i = 0; i < N; i ++)
        {
            if(!father[i])
                ans ++;
        }
        cout<< ans<< endl;
    }
}
