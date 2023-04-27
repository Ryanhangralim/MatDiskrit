#include<bits/stdc++.h>
using namespace std;

int main()
{
    int jumlahkode;
    //meminta input user
    cout<<"Masukkan Jumlah Kode: ";
    cin>>jumlahkode;
    
    //deklarasi variabel
    int kode[jumlahkode];
    int jumlahvertex = jumlahkode+2;
    int vertex[jumlahvertex];
    int edge[jumlahvertex-1][2];

    //mengisi array kode 
    cout<<"Masukkan kode (dipisah dengan spasi): ";
    for(int i = 0; i<jumlahkode; i++)
    {
        cin>>kode[i];
    }
    
    //mengisi array vertex
    for(int i = 0, j = 1; i<jumlahvertex; i++)
    {
        vertex[i]=j;
        j++;
    }
        cout<<endl<<"Vertex: "<<endl;
        for (int i = 0; i < jumlahvertex; i++)
        {
            cout<<vertex[i]<<" ";
        }
        
        cout<<endl<<"Kode: "<<endl;
        for (int i =0; i<jumlahkode; i++)
        {
            cout<<kode[i]<< " ";
        }

    //memilih digit pertama pada kode
    bool x;
    for(int i = 0; i< jumlahkode; i++)
    {
        edge[i][0]= kode[i];

        //mencari nilai pada array vertex digit pertama yang nilai tidak ada pada array kode
        for(int j = 0; j<jumlahvertex; j++)
        {
            while(x==false)
            {
                for(int k = 0; k<jumlahkode; k++)
                {
                    if(vertex[j]==kode[k])
                    {
                        x = true;
                        break;
                    }
                }
                edge[j][1]=vertex[j];
            }
        }
        kode[i]=0;
        
    }
    
    cout<<endl<<"Edge: "<<endl;
    for(int i = 0; i <jumlahkode; i++)
    {
        cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
    }

    return 0;
}


