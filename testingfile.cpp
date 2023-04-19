#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text;
    int c;

    ifstream file ("matriks.txt");
    int myArray[5][5];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
        file >> myArray[i][j];
        }
    }
    for(int i = 0; i < 5; i++)
    {
         for(int j = 0; j < 5; j++){
                cout<<myArray[i][j]<<" ";
         } 
         cout<<"\n";
    }
    myArray[0][0]=0;
    cout<<endl;
    for(int i = 0; i < 5; i++)
    {
         for(int j = 0; j < 5; j++){
                cout<<myArray[i][j]<<" ";
         }
         cout<<"\n";
    }
    file.close();
    return 0;
}