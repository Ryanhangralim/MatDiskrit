#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertex;
    string namaFile;

    //Meminta input jumlah vertex
    cout<<"Masukkan jumlah vertex: ";
    cin>>vertex;
    getchar();
    int matrix[vertex+1][vertex+1]={0};
    int hm[vertex+1]={0};
    int temp[vertex+1]={0};
    int d[vertex+1][2]={0};
    int jumlah, t, t2=0;
    int w[vertex+1]={0};

    //Meminta input nama file
    cout<<"Masukkan nama text file (.txt) yang berisi matrix: ";
    getline(cin, namaFile);

    ifstream file (namaFile+".txt");
    //input dari file ke array
    for(int i = 1; i <= vertex; i++)
    {
        for(int j = 1; j <= vertex; j++)
        {
            file >> matrix[i][j];
        }
    }
    file.close();

    //print matriks
    for(int i = 1; i <= vertex; i++)
    {
         for(int j = 1; j <= vertex; j++){
                cout<<matrix[i][j]<<" ";
         } 
         cout<<"\n";
    }
    /*mengisi array hm dengan vertex yang terhubung ke vertex 1*/
    for(int i=2; i<=vertex; i++)
    {
        hm[i]=matrix[1][i];
    }
    
    //Perubahan nilai hm
        for(int j=2; j<=vertex; j++)
        {
            for (int k = 2; k <= vertex; k++)
            {
                if((matrix[j][k]==1)and(hm[k]==0))
                {
                   hm[k]=1;
                }
            }
        }

    for(int i = 2; i<=vertex; i++ )
    {
        cout<<hm[i]<<" ";
        jumlah = jumlah + hm[i];
    }

    if(jumlah==vertex-1)
    {
        cout<<"\nTerhubung";
    }
    else
    {
        cout<<"\nTidak Terhubung";
    }

    for(int i = 1; i<=vertex; i++) //menghitung derajat
    {
        d[i][0]=i;
        for(int j=1; j<=vertex; j++)
        {
            if(i!=j)
            {
                if(matrix[i][j]==1)
                {
                    d[i][1]++;
                }
                else matrix[i][j]=0;
            }
        }
    }
    
    for(int i=1;i<=vertex;i++)
    {
        cout<<"\n"<<"Derajat vertex "<<d[i][0]<<" adalah "<<d[i][1];
    }

    for(int i=1; i<=vertex; i++)
    {
        for(int j=i+1; j<=vertex; j++)
        {
            if(d[i][1]<d[j][1])
            {
                t=d[i][1];
                d[i][1]=d[j][1]; //mengubah derajat vertex
                d[j][1]=t;

                t2=d[i][0]; //mengubah urutan vertex
                d[i][0]=d[j][0];
                d[j][0]=t2;
            }
        }
    }
    
    cout<<endl<<"Tampilan urutan vertek sesuai derajat"<<endl;
    for(int i = 1; i <= vertex; i++)
    {
        cout<<"Derajat vertek ke "<<d[i][0]<<" adalah "<<d[i][1]<<endl;
    }

    cout<<"Warna vertek"<<endl;
    temp[vertex+1]={0};
    int warna=1;
    w[d[1][0]]= warna;
    int total = 1;
    for(int i=1; i<=vertex; i++)
    {
        temp[i]=matrix[d[1][0]][i];
    }
    while(total<vertex)
    {
        for(int i=1; i<=vertex; i++)
        {
            if((w[d[i][0]]==0)and(temp[d[i][0]]==0))
            {
                w[d[i][0]]=warna;
                total++;
                for (int j=1; j<=vertex; j++)
                {
                    if(temp[j]==0)
                    {
                        temp[j]=temp[j]+matrix[d[i][0]][j];
                    }
                }
            }
        }  
        warna++;
        for(int j=1; j<=vertex;j++)
        {
            temp[j]=0;
        }     
    }

    for(int i=1; i<=vertex; i++)
    {
        cout<<"Warna vertek ke "<<i<<" adalah "<<w[i]<<endl;
    }
    cout<<"Jumlah warna dalam graph adalah: "<<warna-1;
    return 0;
}