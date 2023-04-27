#include<bits/stdc++.h>
using namespace std;

int main()
{
    int array1[]={1,2,3,4,5,6,7};
    int array2[]={1,2,2,2,6};
    int indi = 0;
    int fa = 0;
    vector <pair<int,int>> res;
    vector<int> v;
    for(int i = 0; i<sizeof(array1)/sizeof(array1[0]); i++)
    {
        for(int y = 0; y<sizeof(array2)/sizeof(array2[0]); y++)
        {
            if(array1[i]!=array2[y])
            {
                fa++;
            }
            if(fa==sizeof(array2)/sizeof(array2[0]))
            {
                res.push_back({array2[indi],array1[i]});
                array1[i]=0;
                array2[indi]=0;
                indi++;
                if(array1[])
                for(int i = 0; i<res.size(); i++)
                {
                    cout<<res[i].first<<" "<<res[i].second<<endl;
                }
                cout<<endl;
            }
        }
        fa = 0;
    }
    cout<<endl;
    for(auto x : array1)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x : array2)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i = 0; i<res.size(); i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }

    return 0;
}