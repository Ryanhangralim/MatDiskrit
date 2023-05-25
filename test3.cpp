#include<bits/stdc++.h>
using namespace std;

void pass(int *array)
{
    cout<<*array<<endl; //value at *array
    cout<<array<<endl; //memory of array
    *array = 15;


    int *array2[2][5]; //no value yet
    cout<<"array2 without *:"<<array2[0][0]<<endl; //memory loc of array2[0][0]
    cout<<"array2 with *:"<<*array2[0][0]<<endl; //value of array2[0][0]
    array2[0][0]=array;
    cout<<"array2 without *:"<<array2[0][0]<<endl; //memory loc
    cout<<"array2 with *:"<<*array2[0][0]<<endl; //value = array
    *array2[0][0]= 232;
    cout<<"array2 without *:"<<array2[0][0]<<endl; //memory loc
    cout<<"array2 with *:"<<*array2[0][0]<<endl; //value = 232

    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<5; j++)
        {
            array2[i][j]=array; //adding address to array
            array = array+1;
        }
        
    }
    cout<<"This is array 2 : "<<endl;
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<5; j++)
        {
            cout<<*array2[i][j]<<" "; //printing out value of address
        }
        cout<<endl;
    }
    cout<<"\n";
}

int main()
{
    int array[2][5]={{1,2,3,4,5},{8,9,10,22,45}};
    pass(&array[0][0]);
    // int *ptr = &array[0];
    // cout<<*ptr;
    cout<<"This is array 1: "<<endl;
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<5; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}