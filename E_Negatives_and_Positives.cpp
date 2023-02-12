#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n; cin >> n ;
    vector<int> v(n) ;
    for(auto &x : v) cin >> x  ;


    int totalminus = 0 ;

    for (auto &x : v)
    {
        if (x < 0)
            totalminus++ ;
        x = abs(x);
    }
        
    sort(all(v)) ;

    if((totalminus & 1) == 1) totalminus = 1 ;
    else totalminus = 0 ;


    for(int i = 0 ; i < n; i++)
    {
        if (totalminus <= 0)
            break;
        else 
        {
            v[i] = -abs(v[i]) ;
            totalminus-- ;
        }
    }


    int sum = 0 ;
    for(auto &x : v) sum += x ;

    cout << sum << nl ; 
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
