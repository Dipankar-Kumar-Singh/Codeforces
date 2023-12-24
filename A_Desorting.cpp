#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n ; cin >> n ;
    vector<int> v(n) ; 
    for(auto &x : v) cin >> x ;

    if(!is_sorted(all(v))) {
        cout << 0 << nl ;
        return ; 
    }

    int mn = numeric_limits<int>::max() ;

    for(int i = 0 ; i + 1 < v.size() ; i++){
        mn = min(abs(v[i] - v[i + 1]),mn) ;
    }

    cout << mn/2 + 1 << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
