#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    vector<vector<int>> ans ; 

    vector<int> a ;

    int n ; cin >> n ;
    int orgN = n ;
    n = n * n ;
    int start = 1 ;

    int diff = n - 1 ;

    set<int> s ;

    while(diff > 0)
    {
        a.push_back(start) ;
        if (start + diff <= n and s.count(start + diff) == 0)
        {
            start = start + diff;
            s.insert(start);
        }
        else
        {
            start = start - diff;
            s.insert(start) ;
        }

        diff-- ;
    }

    a.push_back(start) ;

    n = orgN;
    int k = 0 ; 

    int j = 0; 

    for(int i = 0 ; i < n; i++)
    {
        vector<int> v ;
        int k = n ;
        while(k--)
            v.push_back(a[j++]) ;
        
        if(i % 2 != 0) reverse(all(v)) ;
        for(auto x : v) cout << x << " " ; 
        cout << nl ;
    }







}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
