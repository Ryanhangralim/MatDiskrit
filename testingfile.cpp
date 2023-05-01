#include<bits/stdc++.h>
using namespace std;

int main()
{
    int array[6][2]={
        {1, 3},
        {2, 1},
        {2, 4},
        {2, 5},
        {6, 2},
        {6, 7},
    };

    int matriks[7][7]={0};
    
    for(int i = 0; i<6; i++)
    {
        matriks[array[i][0]-1][array[i][1]-1]=1;
        matriks[array[i][1]-1][array[i][0]-1]=1;
    }

    for(int i = 0; i<7; i++)
    {
        for(int j = 0; j<7; j++)
        {
            cout<<matriks[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}