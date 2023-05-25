#include<bits/stdc++.h>
using namespace std;

int main()
{
    int jumlahkode = 5;
    int jumlahvertex = jumlahkode+2;
    int kode[jumlahkode]={1,2,2,2,6};
    int vertex[jumlahvertex]={1,2,3,4,5,6,7};
    int edge[jumlahkode+1][2]={};

    //mencari 5 edge
    
    for(int i = 0; i < jumlahkode; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            bool indicator = false;
            int counter=0;
            for(int k = 0; k<jumlahkode; k++)
            {
                if(vertex[j]!=kode[k])
                {
                    counter++;
                }
                if(counter==jumlahkode)
                {
                    edge[i][0]=kode[i];
                    edge[i][1]=vertex[j];
                    kode[i]=-1;
                    vertex[j]=-1;
                    indicator = true;
                    break;
                }
            }
            if(indicator==true)
            {
                break;
            }
        }
    }

    //mencari 2 angka terakhir
    bool k = false;
    for(int i = 0; i<jumlahvertex; i++)
    {
        if((vertex[i] != -1) && (k == false))
        {
            edge[jumlahkode][0]=vertex[i];
            vertex[i]=-1;
            k=true;
        }
        else if((vertex[i]!=-1) && (k == true))
        {
            edge[jumlahkode][1]=vertex[i];
            vertex[i]=-1;
        }
    }

    //print edge
    for(int i = 0; i<jumlahkode+1; i++)
    {
        cout<<edge[i][0]<<" "<<edge[i][1]<<"\n";
    }
    return 0;
}