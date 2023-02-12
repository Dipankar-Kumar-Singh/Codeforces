#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n; cin >> n ;
    int m ; cin >> m ;

    vector<int> v (n) ;
    vector<int> t (m) ;
    for(auto &x : v) cin >>  x;
    for(auto &x : t) cin >>  x;

    sort(all(v)) ;
    multiset<int> s (all(v)) ;

    for(auto x : t)
    {
        auto it = s.begin() ;
        s.erase(it) ;
        s.insert(x) ;
    }

    v.clear() ;
    for(int i : s) v.push_back(i) ;

    cout << accumulate(all(v),0LL) << nl ;
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
