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
    cout<<"Masukkan nama text file (.txt) yang berisi matriks: ";
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

    cout<<endl;
    cout<<"Matriks ketetanggan:\n";

    //deklarasi matriks
    int matriks[jumlahvertex][jumlahvertex]={};

    for(int i = 0; i<jumlahvertex-1; i++)
    {
        matriks[edge[i][0]-1][edge[i][1]-1]=1;
        matriks[edge[i][1]-1][edge[i][0]-1]=1;
    }

    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            cout<<matriks[i][j]<<" ";
        }
        cout<<endl;
    }

}

//Function untuk cek apakah graf memenuhi syarat untuk graf euler
bool syaratEuler(int *matriks, int jumlahvertex)
{
    //membuat matriks sementara untuk menampung matriks
    int tempMatriks[jumlahvertex][jumlahvertex];
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            tempMatriks[i][j]=*matriks;
            matriks = matriks + 1;
        }
    }

    //deklarasi variabel
    int temp[jumlahvertex-1]={0};
    int cek[jumlahvertex-1]={0};
    int derajat[jumlahvertex]={0};
    int terhubung= 0;
    bool grafterhubung=false;
    bool grafEuler=false;

    //Tahap 1: Cek syarat euler 1 (graph terhubung)
    //mengisi array cek dengan vertex yang terhubung dengan vertex 1
    for(int i = 1, j = 0; i < jumlahvertex; i++)
    {
        cek[j]=tempMatriks[0][i];
        j++;
    }

    for(int i = 0; i < jumlahvertex-1; i++)
    {
        for(int j = 0; j < jumlahvertex-1; j++)
        {
            if(tempMatriks[i][j]==1 && cek[j]==0)
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

    //jika vertex terhubung semua, maka graf terhubung
    if(terhubung==jumlahvertex-1)
    {
        grafterhubung = true;
    }

    //Tahap 2: Cek syarat euler 2 (derajat)
    if(grafterhubung == true)
    {
        for(int i = 0; i<jumlahvertex; i++)
        {
            for(int j = 0; j<jumlahvertex; j++)
            {
                derajat[i]+=tempMatriks[i][j];
            }
        } 
    }

    //mencari jumlah derajat ganjil dan genap
    int ganjil, genap;
    ganjil = genap = 0;
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
        grafEuler=true;
    }
    return grafEuler;
}

//Function untuk mencari vertex awal
int cariVertexAwal(int *matriks, int jumlahvertex)
{
    //membuat matriks sementara untuk menampung matriks
    int tempMatriks[jumlahvertex][jumlahvertex];
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            tempMatriks[i][j]=*matriks;
            matriks = matriks + 1;
        }
    }

    //mencari vertex awal
    for(int i = 0; i<jumlahvertex; i++)
    {
        int derajat = 0;
        for(int j = 0; j<jumlahvertex; j++)
        {
            if(tempMatriks[i][j])
            {
                derajat++; //menghitung jumlah derajat pada vertex
            }
        }
        if(derajat % 2 != 0)
        {
            return i; //jika derajat vertex ganjil, maka vertex tersebut menjadi vertex awal
        }
    }
    return 0; //jika semua derajat vertex genap, maka mulai dari vertex terkecil
}

//Function untuk mengecek apakah edge adalah bridge
bool isBridge(int u, int v, int *matriks, int jumlahvertex)
{
    //membuat matriks sementara untuk menampung matriks
    int *tempMatriks[jumlahvertex][jumlahvertex];
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            tempMatriks[i][j]=matriks;
            matriks = matriks + 1;
        }
    }

    int derajat = 0;
    for(int i = 0; i<jumlahvertex; i++)
    {
        if(*tempMatriks[v][i])
        {
            derajat++;
        }
    }
    if(derajat>1)
        {
            return false; //edge bukan jembatan/bridge
        }
    return true; //edge adalah jembatan/bridge
}

//Function untuk menghitung edge
int hitungEdge(int *matriks, int jumlahvertex)
{
    //membuat matriks sementara untuk menampung matriks
    int *tempMatriks[jumlahvertex][jumlahvertex];
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            tempMatriks[i][j]=matriks;
            matriks = matriks + 1;
        }
    }

    int count = 0;
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = i; j<jumlahvertex; j++)
        {
            if(*tempMatriks[i][j])
            {
                count++;
            }
        }
    }
    return count; //menghitung jumlah edge dalam graph
}

//fungsi untuk algoritma fleury
void fleury(int start, int *matriks, int jumlahvertex)
{
    //membuat matriks sementara untuk menampung matriks
    int *tempMatriks[jumlahvertex][jumlahvertex];
    for(int i = 0; i<jumlahvertex; i++)
    {
        for(int j = 0; j<jumlahvertex; j++)
        {
            tempMatriks[i][j]=matriks;
            matriks = matriks + 1;
        }
    }

    int edge = hitungEdge(tempMatriks[0][0], jumlahvertex);
    for(int v = 0; v<jumlahvertex; v++) 
    {
        if(*tempMatriks[start][v])
        {
            if(edge <= 1 || !isBridge(start, v, tempMatriks[0][0], jumlahvertex)) //edge digunakan jika ada dan bukan jembatan/bridge
            {
                cout<< start+1 << "--" << v+1 << " "<<endl;
                *tempMatriks[start][v] = *tempMatriks[v][start] = 0; //menghapus edge dari graf
                edge--; 
                fleury(v, tempMatriks[0][0], jumlahvertex);
            }
        }
    }
}

void euler()
{
    int jumlahvertex;
    string namaFile;

    //meminta input jumlah vertex
    cout<<"Masukkan jumlah vertex: ";
    cin>>jumlahvertex;
    getchar();

    //deklarasi variabel
    int matriks[jumlahvertex][jumlahvertex]={};

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

    if(syaratEuler(&matriks[0][0], jumlahvertex)==1)
    {
        cout<<"Syarat euler terpenuhi\n";
        cout<<"Graf euler atau lintasan euler: \n";
        fleury(cariVertexAwal(&matriks[0][0], jumlahvertex), &matriks[0][0], jumlahvertex);
    }
    else if(syaratEuler(&matriks[0][0], jumlahvertex)==0)
    {
        cout<<"Graf tidak memenuhi syarat euler";
    }
}

int main()
{
    int pilihan;
menu:
    cout<<"Menu: \n";
    cout<<"1. Pengkodean pohon\n";
    cout<<"2. Rekonstruksi pohon\n";
    cout<<"3. Graf Euler\n";
    cout<<"4. Keluar\n";
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
            //euler
            euler();
            getchar();
            goto menu;
        break;
        
        case 4:
            exit(0);
        break;
    }

    return 0;
}