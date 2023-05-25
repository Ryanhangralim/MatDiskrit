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
    int T[6]={};
    int p, v, vn, k, m, mst;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

    v = 0;
    T[0]=1;
    mst=0;
    k=1;
    while(k<=5)
    {
        m=999;
        p=0;
        while(p<=5)
        {
            if(T[p]==1)
            {
                for(int i = 0; i<=5; i++)
                {
                    if((M[p][i]<m)&&(M[p][i]!=0)&&(T[i]!=1)&&(p!=i))
                    {
                        m=M[p][i];
                        v=p;
                        vn=i;
                    }
                }
            }
            p++;
        }
        cout<<endl<<v<<" - "<<vn<<endl;
        mst=mst+m;
        T[vn]=1;
        k++;
    }
    cout<<endl<<mst;


    return 0;
}