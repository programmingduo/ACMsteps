    #include <iostream>
    #include <cstdio>
    #include <string>
    #include <map>
    using namespace std;

    map<string,double> vis;
    int main()
    {
        int ID,N;
        string s;
        vis["A"] = 4.0, vis["A-"] = 3.7, vis["B+"] = 3.3;
        vis["B"] = 3.0, vis["B-"] = 2.7, vis["C+"] = 2.3;
        vis["C"] = 2.0, vis["C-"] = 1.7, vis["D"] = 1.3;
        vis["D-"] = 1.0, vis["F"] = 0;
        while(~scanf("%d",&N))
        {
            double fenzi = 0,fenmu = 0;
            while(N--)
            {
                cin>>ID>>s;
                if(s == "P" || s == "N") continue;
                fenzi += ID*vis[s], fenmu +=ID;
            }
            if(fenmu == 0) printf("0.00\n");
            else
            {
                double temp = fenzi/fenmu;
                printf("%.2lf\n",temp);
            }
        }
        return 0;
    }
