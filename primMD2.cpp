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

    //menghitung jumlah edge
    int jumlahedge = 0;
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = i; j<jumlahvertex; j++)
        {
            if(matriks[i][j])
            {
                jumlahedge++;
            }
        }
    }

    //deklarasi variabel
    int T[jumlahvertex]={};
    int p, v, vn, k, m, mst;

    v=0;
    T[0]=1;
    mst = 0;
    k=1;
    while(k<=jumlahvertex-1)
    {
        m=999;
        p=0;
        while(p<=jumlahvertex-1)
        {
            if(T[p]==1)
            {
                for(int i = 0; i<=jumlahvertex-1; i++)
                {
                    if((matriks[p][i]<m)&&(matriks[p][i]!=0)&&(T[i]!=1)&&(p!=i))
                        {
                            m=matriks[p][i];
                            v=p;
                            vn=i;
                        }
                }
            }
            p++;
        }
        cout<<v<<" - "<<vn<<endl;
        mst=mst+m;
        T[vn]=1;
        k++;
    }
    cout<<endl<<"MST: "<<mst;
    return 0;
}