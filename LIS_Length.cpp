#include<bits/stdc++.h>
using namespace std ;

int LIS_Length( vector<int> &v )
{
    vector<int> lis ;
    for(auto &x : v)
    {
        if(lis.empty() or lis.back() < x)
        {
            lis.push_back(x) ;
        }

        else 
        {
            auto it = lower_bound(begin(lis),end(lis),x) ;
            *it = x ; 
        }
    }
    return lis.size() ;
}

int main()
{ 
    // int n;  cin >> n ;

    vector<int> v ; 
    // for(auto &x : v) 
    //     cin >> x ;

    v = {10,9,2,5,3,7,101,18} ;
    cout << LIS_Length(v) ;
}