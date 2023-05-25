#include<bits/stdc++.h>
using namespace std;

void syaratEuler(int *matriks, int jumlahvertex)
{
    int tempMatriks[jumlahvertex][jumlahvertex];
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            tempMatriks[i][j]=*matriks;
            matriks = matriks + 1;
        }
    }

    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j =0; j<jumlahvertex; j++)
        {
            cout<<tempMatriks[i][j];
        }
        cout<<endl;
    }
}


int main()
{
    int jumlahvertex;
    string namaFile;

    //meminta input jumlah vertex
    cout<<"Masukkan jumlah vertex: ";
    cin>>jumlahvertex;
    getchar();

    //deklarasi variabel
    int matriks[jumlahvertex][jumlahvertex]={0};
    int temp[jumlahvertex-1]={0};
    int cek[jumlahvertex-1]={0};
    int derajat[jumlahvertex]={0};
    int terhubung= 0;
    bool grafterhubung=false;

    //meminta nama file
    cout<<"Masukkan nama text file (.txt) yang berisi matriks: ";
    getline(cin,namaFile);

    //menginput matriks dari file
    ifstream file (namaFile+".txt");
    for(int i = 0; i < jumlahvertex; i++)
    {
        for(int j = 0; j < jumlahvertex; j++)
        {
            file >> matriks[i][j];
        }
    }
    file.close();

    syaratEuler(&matriks[0][0], jumlahvertex);
    return 0;
}