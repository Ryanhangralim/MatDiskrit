#include<bits/stdc++.h>
using namespace std;

void kodepohon()
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

    cout<<"k: "<<k<<" l: "<<l<<endl;
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
}

void rekonstruksipohon()
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
}

int main()
{
    int pilihan;
menu:
    cout<<"Menu: \n";
    cout<<"1. Pengkodean pohon\n";
    cout<<"2. Rekonstruksi pohon\n";
    cout<<"3. Keluar\n";
    cout<<"Pilhan: ";
    cin>>pilihan;
    getchar();

    switch(pilihan)
    {
        case 1:
            kodepohon();
            getchar();
            goto menu;
        break;

        case 2:
            rekonstruksipohon();
            getchar();
            goto menu;
        break;
        
        case 3:
            exit(0);
        break;
    }

    return 0;
}