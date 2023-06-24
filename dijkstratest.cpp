#include <iostream>
#include <istream>
#include <fstream>

using namespace std;

int adjmtx[100][100];
int getShortest[100];
bool isVisited[100];

void GetShortest(int target, int vertex)
{
    int i;

    //masukkan nilai dari 2 array yang digunakan
    for (int j=0 ; j<vertex; j++){
        getShortest[j] = -1;
        isVisited[j] = false;
    }

    bool repeat = true;
    int start = target;

    getShortest[start] = 0;
    while (repeat)
    {
        isVisited[start] = true;
        for (i = 0; i < vertex; i++)
        {
            if ((adjmtx[start][i] != 0) && (!isVisited[i]))
            {
                if ((start == target) && (getShortest[i] == -1))
                {
                    getShortest[i] = adjmtx[start][i];
                }
                else
                {
                    if (getShortest[i] == -1)
                    {
                        getShortest[i] = getShortest[start] + adjmtx[start][i];
                    }
                    else
                    {
                        if (getShortest[start] + adjmtx[start][i] < getShortest[i])
                        {
                            getShortest[i] = getShortest[start] + adjmtx[start][i];
                        }
                    }
                }
            }
        }
        int minimumVertex = -1;
        repeat = false;
        for (i = 0; i < vertex; i++)
        {
            if ((!isVisited[i]) && (getShortest[i] != -1))
            {
                repeat = true;
                if (minimumVertex == -1)
                {
                    minimumVertex = getShortest[i];
                    start = i;
                }
                else
                {
                    if (getShortest[i] < minimumVertex)
                    {
                        minimumVertex = getShortest[i];
                        start = i;
                    }
                }
            }
        }
    }
}

int main()
{
    int vertex;
    string FileName;

    cout << "Masukkan jumlah vertex: ";
    cin >> vertex;
    adjmtx[vertex][vertex] = {0};

    
    cout << "Masukkan nama file yang berisi matriks ketetanggaan yang berbobot: \nNama: ";
    cin >> FileName;
    ifstream file (FileName + ".txt");
    //input dari file ke array
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            file >> adjmtx[i][j];
        }
    }
    file.close();
    
    for (int i=0; i<vertex; i++){
        for (int j=0; j<vertex; j++){
            cout << adjmtx[i][j] << "\t";
        }
        cout << endl;
    }


    int target;
    cout << "Pilih vertex awal: ";
    cin >> target;
    target--;
    GetShortest(target, vertex);

    // print
    for (int i = 0; i < vertex; i++)
    {
        cout << target + 1 << " --> " << i + 1 << "= " << getShortest[i] << endl;
    }

    return 0;
}