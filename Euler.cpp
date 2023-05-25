#include<bits/stdc++.h>
using namespace std;

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
    bool syaratEuler=false;

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

    //mengisi array cek dengan vertex yang terhubung dengan vertex 1
    for(int i = 1, j = 0; i < jumlahvertex; i++)
    {
        cek[j]=matriks[0][i];
        j++;
    }

    for(int i = 0; i < jumlahvertex-1; i++)
    {
        for(int j = 0; j < jumlahvertex-1; j++)
        {
            if(matriks[i][j]==1 && cek[j]==0)
            {
                cek[j]=1;
            }
        }
    }

    //menghitung jumlah vertex yang terhubung
    for(auto x : cek)
    {
        terhubung += x;
    }

    if(terhubung==jumlahvertex-1)
    {
        grafterhubung = true;
    }

    //mengecek syarat 2 euler
    if(grafterhubung == true)
    {
        for(int i = 0; i<jumlahvertex; i++)
        {
            for(int j = 0; j<jumlahvertex; j++)
            {
                derajat[i]+=matriks[i][j];
            }
        }
        
    }

    //mencari jumlah derajat ganjil dan genap
    int ganjil, genap = 0;
    for(auto x : derajat)
    {
        if(x%2==0)
        {
            genap++;
        }
        else if(x%2!=0)
        {
            ganjil++;
        }
    }

    if(((ganjil==2) && (genap=jumlahvertex-2)) || ((ganjil==0) && (genap==jumlahvertex)))
    {
        syaratEuler = true;
    }

    if(syaratEuler==true)
    {
        cout<<"Syarat euler terpenuhi";
    }
    else if(syaratEuler==false)
    {
        cout<<"Syarat euler tidak terpenuhi";
    }
    
    
   

    

    
    return 0;
}