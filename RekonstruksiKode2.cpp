#include<bits/stdc++.h>
using namespace std;

int main()
{
    int jumlahkode;
    cout<<"Masukkan jumlah kode: ";
    cin>>jumlahkode;

    //deklarasi variabel
    int jumlahvertex = jumlahkode+2;
    int kode[jumlahkode];
    int vertex[jumlahvertex]={0}; //mengisi array vertex dengan 0
    int edge[jumlahvertex-1][2];

    //mengisi array kode dengan input user
    cout<<"Masukkan kode (dipisah dengan spasi): ";
    for(int i = 0; i < jumlahkode; i++)
    {
        cin>>kode[i];
    }

    //mencari berapa total angka vertex dalam kode
    for(int i = 0; i<jumlahkode; i++)
    {
        vertex[kode[i] - 1] +=1;
    }

    //mencari angka vertex terkecil yang tidak ada pada array kode
    int x = 0;
    for(int i = 0; i < jumlahkode; i++)
    {
        for(int j = 0; j < jumlahvertex; j++)
        {
            if(vertex[j]==0)
            {
                vertex[j]=-1;
                edge[x][1]=j+1;
                edge[x][0]=kode[i];
                vertex[kode[i] - 1]--;
                x++;

                break;
            }
        }
    }

    //mencari 2 angka terakhir
    int k = 0;
    int n1, n2;
    for (int i = 0; i < jumlahvertex; i++)
    {
        if(vertex[i]==0 && k == 0)
        {
            n1 = i + 1;
            k++;
        }
        else if(vertex[i]==0 && k == 1)
        {
            n2 = i + 1;
        }
    }

    edge[jumlahvertex-2][0]=n1;
    edge[jumlahvertex-2][1]=n2;

    cout<<"Edge: "<<endl;
    for(int i = 0; i < jumlahvertex-1; i++)
    {
        cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
    }

    
    return 0;
}