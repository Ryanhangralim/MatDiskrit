#include<bits/stdc++.h>
using namespace std;

int main()
{
    int M[6][6]={{0, 10, 0, 30, 45, 0},
                 {10, 0, 50, 0, 40, 25},
                 {0, 50, 0, 0, 35, 15},
                 {30, 0, 0, 0, 0, 20},
                 {45, 40, 35, 0, 0, 55},
                 {0, 25, 15, 20, 55, 0}};

    int E[2][10]={{0,2,3,1,0,2,1,0,1,4},{1,5,5,5,3,4,4,4,3,5}};
    int T[6][6]={};
    int w[6];
    int v, v1, v2, k, m, mst;

    k = 1; mst = 0;
    for(int i = 0; i<=9; i++)
    {
        if(k<=5)
        {
            v1=E[0][i]; 
            v2=E[1][i];
            //set w menjadi 0 semua
            w[6]={};

            for(int j = 0; j<=5; j++)
            {
                w[j]=T[v1][j];
            }

            int cek = 0;
            while(cek<=5){   
                for(int j = 0; j<=5; j++)
                {
                    if(w[j]==1)
                    {
                        for(int x = 0; x<=5;x++)
                        {
                            if(T[j][x]==1)
                            {
                                w[x]=1;
                            }
                        }
                    }
                }
                cek++;
            }

            if(w[v2]==0)
            {
                T[v1][v2]=1;
                T[v2][v1]=1;
                mst=mst+M[v1][v2];
                cout<<endl<<v1<<"-"<<v2<<" bobot "<<M[v1][v2]<<" total MST = "<<mst;
                M[v1][v2]=0;
                M[v2][v1]=0;
                k++;
                cout<<endl;
                
            }
            for(int o = 0; o<=5; o++)
                {
                    for(int x = 0; x<=5; x++)
                    {
                        cout<<T[o][x]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                for(auto x : w)
                {
                    cout<<x<<" ";
                }cout<<endl;
        }
    }
    return 0;
}