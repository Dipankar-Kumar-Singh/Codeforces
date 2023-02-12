#include<bits/stdc++.h>
using namespace std ;

vector<int> LIS(vector<int> v)
{
    int n = v.size() ;
    vector<int> lis ;
    vector<int> insertedAt (n+1) ;

    for(int i = 0 ; i < n ;i++)
    {
        int curr = v[i] ;

        if(lis.empty() or lis.back() < curr)
        {
            lis.push_back(curr) ;
            insertedAt[i] = lis.size()  ;
        }
        else 
        {
            // all(lis) , not all(v) X   //
            auto it = lower_bound(begin(lis),end(lis),curr) ;
            *it = curr ;
            // lis.begin() --> not v.bgin()  //
            insertedAt[i] = it - lis.begin() + 1 ;
        }
    }

    int currLen = lis.size() ;

    cout << "Lis is of Size = " << currLen  << endl ;

    vector<int> series ;

    for(int i = n - 1 ; i >= 0 ; i--)
    {
        if(insertedAt[i] == currLen)
        { 
            series.push_back(v[i]) ;
            currLen-- ;
        }
    }

    reverse(begin(series),end(series)) ;
    return series ;

}

int main()
{

    for(auto x : LIS({1 , 5 , 7 , 10 , 9 , 6 , 7 , 9 , 2 , 3}))
    {
        cout << x <<  " " ;
    }
    cout << endl ;
}