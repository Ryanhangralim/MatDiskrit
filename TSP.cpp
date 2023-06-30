#include<bits/stdc++.h>
using namespace std;

int faktorial(int x)
{
    if(x>1)
    {
        return x * faktorial(x - 1);
    }
    else{
        return 1;
    }
}

struct data{
    vector<int>path;
    int weight;
};

int main()
{
    string namaFile;
    int jumlahvertex;

    //meminta input
    cout<<"Masukkan Jumlah Vertex: ";
    cin>>jumlahvertex; getchar();
    int line = faktorial(jumlahvertex-1);

    //deklarasi variabel
    int matriks[jumlahvertex][jumlahvertex]={};
    struct data tsp[line];
    
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
            if((matriks[i][j]==0)&&(i!=j)){
                matriks[i][j]=9999;
            }
        }
    }
    file.close();

    //meminta vertex asal/awal
    int awal;
    cout<<"Vertex awal: ";
    cin>>awal; getchar();
    awal-=1;
    
    //mengisi kolom pertama dengan vertex asal/awal
    //mengisi nilai 0 pada bobot awal
    for(int i = 0; i<line; i++)
    {
        tsp[i].path.push_back(awal+1);
        tsp[i].weight=0;
    }

    int vertexTujuan[jumlahvertex-1];

    //mengisi array vertexTujuan
    int x = 0;
    for(int i = 0; i<jumlahvertex; i++)
    {
        if(i!=awal)
        {
            vertexTujuan[x]=i+1;
            x++;
        }
    }

    //permutasi (mengisi semua kemungkinan)
    x = 0;
        do{
            for(int j = 0; j<jumlahvertex-1; j++)
            {
                tsp[x].path.push_back(vertexTujuan[j]);
            }
            x++;
        }
        while(next_permutation(vertexTujuan, vertexTujuan+jumlahvertex-1));

    //mengisi jalur terakhir kembali ke vertex awal
    for(int i = 0; i<line; i++)
    {
        tsp[i].path.push_back(awal+1);
    }

    //mengisi bobot
    for(int i = 0; i<line; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            tsp[i].weight+=matriks[tsp[i].path[j]-1][tsp[i].path[j+1]-1];
        }
    }

    //mencari bobot terkecil
    int result = 0;
    int min_weight = tsp[0].weight;
    for(int i = 1; i<line; i++)
    {
        if(tsp[i].weight<min_weight)
        {
            min_weight=tsp[i].weight;
            result = i;
        }
    }

    cout<<"Bobot terkecil: "<<min_weight;
    cout<<"\nJalur: ";
    for(int i = 0; i<jumlahvertex; i++)
    {
        cout<<tsp[result].path[i]<<" -> ";
    }
    cout<<tsp[result].path[jumlahvertex];

    return 0;
}