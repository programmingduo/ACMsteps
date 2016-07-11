#include <iostream>
#include<cstring>
#include <queue>

using namespace std;

#define MAXSTATUS 65535

#define ALLSAME(X) X==0 || X == MAXSTATU S


unsigned int oxrMatrix[] =

{

        0xC800,0xE400,0x7200,0x3100,

 0x8C80,0x4E40,0x2720,0x1310,

 0x08c8,0x04E4,0x0272,0x0131,

 0x008c,0x004E,0x0027,0x0013,


};


unsigned int allStatus[MAXSTATUS];


int bsf(unsigned int c)

{

        int i;

       unsigned int tmp;

    queue<unsigned int> statuses;

  statuses.push(c);

    while(!statuses.empty())

     {

            c = statuses.front();

                statuses.pop();

              for( i = 0; i < 16; i++)

              {

                    tmp = c ^ oxrMatrix[i];

                      if(ALLSAME(tmp))

                     {

                            return allStatus[c] + 1;

                     }

                    if(!allStatus[tmp]) // current status is not visited before

                  {

                            allStatus[tmp] = allStatus[c] + 1;

                           statuses.push(tmp);

                  }



             }

    }

    return 0;

}

int main()

{

   int i;


    unsigned int status = 0;

     char tmpC;

   int nStep;

   while(cin>>tmpC)

       {

            if(tmpC == 'b')

              {

                    status = 1;

          }

            for( i = 1; i < 16; i++)

              {

                    cin>>tmpC;

                     status *= 2;

                 if(tmpC == 'b')

                      {

                            status += 1;

                 }

            }

            if(ALLSAME(status))

          {

                    cout<<"0\n"<<endl;

               }

            else

         {

                    memset(allStatus,0,sizeof(allStatus));

                       nStep = bsf(status);

                 if(!nStep)

                   {

                            cout<<"Impossible\n"<<endl;

                      }

                    else

                 {

                            cout<<nStep<<endl;

                       }

            }

    }

    return 0;

}
