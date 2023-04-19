#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Before:\n";
    int x = 20;
    cout<<"Current value of x is : "<<x<<endl;
    int *ptr = &x;
    cout<<"Current value of ptr is: "<<ptr<<endl;
    cout<<"Current value of *ptr is: "<<*ptr;

    cout<<endl;
    cout<<"After:"<<endl;

    *ptr = 30;
    cout<<"Current value of x is : "<<x<<endl;
    cout<<"Current value of ptr is: "<<ptr<<endl;
    cout<<"Current value of *ptr is: "<<*ptr;
    return 0;
}