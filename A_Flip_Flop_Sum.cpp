#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
     int n ; cin >>  n ;
     vector<int> v(n) ;
     for(auto &x : v) cin >> x ;

    int sum = accumulate(all(v),0LL) ;

    int best = -1e15 ;
    
    for(int i = 0 ; i + 1 < n;  i++)
    {
        int s = sum ;
        s -= (v[i] + v[i + 1]) ;
        s += ( -v[i] - v[i + 1]) ;
        best = max(best,s) ;
    }

    cout << best << nl ;
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
