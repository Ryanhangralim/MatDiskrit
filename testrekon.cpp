#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool vertex[8]={0,1,1,1,1,1,1,1};
    int kode[6]={0,1,2,2,2,6};
    int hasil[5]={0};

    for(int i = 1; i<=5; i++)
    {
        int x = kode[i];
        bool k = false;
        int j = 1;
            while(!k)
            {
                for(int m = 1; m<=5; m++)
                {
                    if(kode[m]==j)
                    {
                        vertex[j]=0;
                        j++;
                        break;
                    }
                    else
                    {
                        if(m==5)
                        {
                            if(vertex[j]==1)
                            {
                                k=true;
                            }
                            else
                            {
                                j++;
                            }
                        }
                    }
                }
            }
            kode[i]=0;
            vertex[j]=0;
    }
    int y=0;
    for(int p = 1; p <=7; p++)
    {
        if(vertex[p]==1)
        {

            hasil[y]=vertex[p];
            y++;
        }
    }
    for(int i=0; i<sizeof(hasil)/sizeof(hasil[0]); i++)
    {
        cout<<hasil[0]<<" ";
    }

    return 0;
}