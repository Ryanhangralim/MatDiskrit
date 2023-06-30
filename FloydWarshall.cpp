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
    int d[jumlahvertex][jumlahvertex]={};

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
                matriks[i][j]=999;
            }
        }
    }
    file.close();  

    for(int k = 0; k<jumlahvertex; k++)
    {
        for(int i = 0; i<jumlahvertex; i++)
        {
            for(int j = 0; j<jumlahvertex; j++)
            {
                if(i==j)
                {
                    d[i][j]=0;
                }
                else if((i==k)||(j==k))
                {
                    d[i][j]=matriks[i][j];
                }
                else{
                    if(matriks[i][j]<matriks[i][k]+matriks[k][j])
                    {
                        d[i][j]=matriks[i][j];
                    }
                    else{
                        d[i][j]=matriks[i][k]+matriks[k][j];
                    }
                }
            }
        }
        for(int i = 0; i<jumlahvertex; i++)
        {
            for(int j = 0; j<jumlahvertex; j++)
            {
                matriks[i][j]=d[i][j];
            }
        }
    }

    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}