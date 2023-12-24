#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(auto &x : v ) cin >> x ; 
    sort(all(v)) ;

    int best = 0 ;

    for(int test = 0 ; test < n ; test++) {
        v[test]++ ;
        long long product = 1 ;
        for(auto &x : v) product *= x ;
        best = max(best, product ) ;
        v[test]-- ;
    }

    cout << best << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
