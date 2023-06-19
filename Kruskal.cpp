#include<bits/stdc++.h>
using namespace std;

int main()
{
    int jumlahvertex;
    string namaFile;

    //meminta input user
    cout<<"Masukkan jumlah vertex: ";
    cin>>jumlahvertex;
    getchar();

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

    vector<pair<int,pair<int,int>>> edges;

    //menghitung jumlah edge dan mendata edge
    int jumlahedge = 0;
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = i; j<jumlahvertex; j++)
        {
            if(matriks[i][j])
            {
                jumlahedge++;
                edges.push_back(make_pair(matriks[i][j], make_pair(i,j)));
            }
        }
    }

    cout<<endl<<"Jumlah edge: "<<jumlahedge;

    //deklarasi variabel
    int temp[jumlahvertex][jumlahvertex]={};
    int w[jumlahvertex]={};
    int v1, v2, k, mst;

    //mengurutkan edges
    sort(edges.begin(),edges.end());

    k = 1;
    mst = 0;
    for(int i = 0; i<jumlahedge; i++)
    {
        if(k<=jumlahvertex-1)
        {
            v1=edges[i].second.first;
            v2=edges[i].second.second;
            //set w ke 0
            w[jumlahvertex]={};

            for(int j = 0; j<jumlahvertex; j++)
            {
                w[j]=temp[v1][j];
            }

            int cek = 0;
            while(cek<jumlahvertex)
            {
                for(int j = 0; j<jumlahvertex; j++)
                {
                    if(w[j]==1)
                    {
                        for(int x = 0; x<jumlahvertex; x++)
                        {
                            if(temp[j][x]==1)
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
                temp[v1][v2]=1;
                temp[v2][v1]=1;
                mst+=matriks[v1][v2];
                cout<<endl<<v1<<" - "<<v2<<" bobot "<<matriks[v1][v2]<< " total MST = "<<mst;
                matriks[v1][v2]=0;
                matriks[v2][v1]=0;
                k++;
            }
        }
    }

    return 0;
}