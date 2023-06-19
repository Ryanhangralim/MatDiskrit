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

    //deklarasi variabel
    int v1, k, mst;
    mst=0;
    k=1;
    v1 = 0;
    vector<pair<int,int>>tree;
    vector<pair<int,pair<int,int>>> pq;
    bool visited[jumlahvertex]={};
    visited[0]=true;

    while(k<=jumlahvertex-1)
    {
        //input edge yang terhubung dengan v1
        for(int i = 0; i<jumlahvertex; i++)
        {
            if(matriks[v1][i]!=0)
            {
                pq.push_back(make_pair(matriks[v1][i],make_pair(v1,i)));
            }
        }
        //mengurutkan edge sesuai bobot
        sort(pq.begin(),pq.end());

        //mencari bobot edge dengan bobot terkecil yang terhubung dengan v1
        for(int i = 0; i<pq.size(); i++)
        {
            if((visited[pq[i].second.first]==true)&&(visited[pq[i].second.second]==false))
            {
                tree.push_back(make_pair(pq[i].second.first,pq[i].second.second));
                k++;
                mst+=matriks[pq[i].second.first][pq[i].second.second];
                visited[pq[i].second.second]=true;
                v1 = pq[i].second.second;
                pq.erase(pq.begin()+i);
                break;
            }
        }
    }

    cout<<"MST: "<<mst;

    for(int i = 0; i<tree.size(); i++)
    {
        cout<<endl<<tree[i].first<<" - "<<tree[i].second;
    }

    return 0;
}