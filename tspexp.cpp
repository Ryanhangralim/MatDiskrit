#include<bits/stdc++.h>
using namespace std;

void display(int target[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<target[i]<<" ";
    }
    cout<<endl;
}

void permutations(int target[], int n)
{
    do{
        display(target,n);
    } while(next_permutation(target, target+n));
}

int main()
{
    int target[]={2,3,4};
    permutations(target,3);
    return 0;
}