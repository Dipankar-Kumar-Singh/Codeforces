#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n ; cin >> n ;
    int k ; cin >> k ;

    vector<int> a(n) , b(n) ;
    for(int& i : a) cin >> i ;
    for(int& i : b) cin >> i ;

    int oneTime = 0 ;
    int bestPointTillNow = 0 ;

    int ans = 0 ;

    for(int i = 0 ; i < n ; i++){
        int moves = i + 1 ; 
        if(moves > k) break ;
        oneTime += a[i] ;
        int remainingMoves = k - moves ;
        bestPointTillNow = max( bestPointTillNow , b[i] ) ;
        ans = max( ans , oneTime + (remainingMoves * bestPointTillNow)) ;
    }

    cout << ans << nl ;
        

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
