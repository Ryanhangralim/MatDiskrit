#include<bits/stdc++.h>
using namespace std;

int main()
{

    string namaFile;
    int jumlahvertex;

    //meminta input
    cout<<"Masukkan Jumlah Vertex: ";
    cin>>jumlahvertex; getchar();

    //deklarasi variabel
    int matriks[jumlahvertex][jumlahvertex]={};

    //meminta nama file
    cout<<"Masukkan nama file (.txt) yang berisi matriks: ";
    getline(cin, namaFile);

    //input matriks
    ifstream file (namaFile+".txt");
    for(int i = 0; i < jumlahvertex; i++)
    {
        for(int j = 0; j < jumlahvertex; j++)
        {
            file >> matriks[i][j];
        }
    }
    file.close();

    int awal;
    cout<<"Vertex awal: ";
    cin>>awal; getchar();
    awal-=1;

    int d[3][jumlahvertex];
    int v2;

    //inisiasi awal
    for(int i = 0; i<jumlahvertex; i++)
    {
        if(i==awal)
        {
            d[0][i]=0;
            d[1][i]=1;
            d[2][i]=i;
        }
        else{
            d[0][i]=999;
            d[1][i]=0;
            d[2][i]=0;
        }
    }

    //mencari shortest path
    for(int k = 0; k<jumlahvertex; k++)
    {
        int x = 9999;
        for(int i = 0;i<jumlahvertex; i++)
        {
            if(d[1][i]==1){
                for(int j = 0; j<jumlahvertex; j++)
                {
                    if(matriks[i][j]!=0)
                    {
                        if((d[0][i]+matriks[i][j])<d[0][j])
                        {
                            d[0][j]=d[0][i]+matriks[i][j];
                            d[2][j]=i;

                        }
                        matriks[i][j]=0;
                        matriks[j][i]=0;
                    }
                }
             }
                for(int m = 0; m<jumlahvertex; m++)
                {
                    if((d[0][m]<x)&&(d[1][m]!=1))
                    {
                        x = d[0][m];
                        v2 = m;
                    }
                }           
        }
        d[1][v2]=1;


    }

    for(int i = 0; i<jumlahvertex; i++)
    {
        cout<<d[0][i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i<jumlahvertex; i++)
    {
        cout<<d[1][i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i<jumlahvertex; i++)
    {
        cout<<d[2][i]+1<<" ";
    }
    cout<<endl;

    cout<<"vertex asal -> vertex tujuan = bobot = jalur\n";
    for(int i = 0; i<jumlahvertex; i++)
    {
        int x = 999;
        cout<<awal+1<<" -> "<<i+1<<" = "<<d[0][i]<<" = "<<i+1<<" <- ";
        if(d[2][i]==awal)
        {
            cout<<d[2][i]+1;
        }
        else{
            x = d[2][i];
            while(x!=awal)
            {
                cout<<x+1<<" <- ";
                x = d[2][x];
            }
            cout<<x+1;
        }
    cout<<endl;

    }
}