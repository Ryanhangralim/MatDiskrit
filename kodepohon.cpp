#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertex;
    string namaFile;

    //meminta input jumlah vertex
    cout<<"Masukkan jumlah vertex: ";
    cin>>vertex;
    getchar();

    //meminta input nama file
    cout<<"Masukkan nama text file (.txt) yang berisi matrix: ";
    getline(cin, namaFile);


    //Deklarasi variabel
    int derajat[vertex]={0};
    int kode[vertex]={0};
    int matriks[vertex][vertex]={0};
    int vt, vh;

    //Input matriks dari file ke array
    ifstream file (namaFile+".txt");
    for(int i = 0; i<vertex; i++)
    {
        for(int j = 0; j<vertex; j++)
        {
            file >> matriks[i][j];
        }
    }
    file.close();

    //Menghitung derajat matriks
    for(int i = 0; i<vertex; i++)
    {
        for(int j = 0; j<vertex; j++)
        {
            derajat[i]+=matriks[i][j];
        }
    }
   
   //Mencari derajat 1 dan kode
   for(int i = 0; i<vertex-2; i++)
   {
    int k = 0;
    while(derajat[k]!=1)
    {
        k++;
    }
    vt = k;
    int l = 0;
    while(matriks[vt][l]!=1)
    {
        l++;
    }
    vh=l;
    kode[i]=vh+1;

    matriks[k][l]=0;
    matriks[l][k]=0;

    //menghapus derajat derajat 
    derajat[k]-=1;
    derajat[l]-=1;

    cout<<"Vt: "<<vt+1<<" Vh: "<<vh+1<<endl;
   }

    //print derajat setelah proses
    cout<<endl<<"Derajat setelah proses: \n";
    for(int i = 0; i<vertex; i++)
    {
        cout<<derajat[i]<<" ";
    }
    cout<<endl;

    //print matriks setelah proses
    cout<<endl<<"matriks setelah proses: \n";
     for(int i = 0; i<vertex; i++)
    {
        for(int j = 0; j<vertex; j++)
        {
            cout<<matriks[i][j]<<" ";
        }
        cout<<endl;
    }

    //print kode pohon
    cout<<endl<<"kode pohon: ";
    for(int i = 0; i<vertex-2; i++)
    {
        cout<<kode[i]<<" ";
    }

    return 0;
}