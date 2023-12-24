#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n; cin >> n ;
    vector<int> v(n) ;

    for(auto &x : v) cin >> x ;

    vector<int> ans = {v[0]};

    for(int i = 1 ; i < n; i++){
        int x = v[i] ;
        if(  x >= ans.back()){
            ans.push_back(x) ;
        } else {
            ans.push_back(x) ;
            ans.push_back(x) ;
        }
    }

    cout << ans.size() << nl ;
    for(auto &x : ans) {
        cout << x <<  " " ; 
    } cout << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
