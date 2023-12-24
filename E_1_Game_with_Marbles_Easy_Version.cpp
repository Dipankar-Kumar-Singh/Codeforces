#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n ; cin >> n ; 
    vector<pair<int,int>> v(n) ;
    for(auto &[x,_] : v) cin >> x ;
    for(auto &[_,y] : v) cin >> y ;

    sort(all(v),[&](pair<int,int> &a , pair<int,int> &b) -> bool { 
        
        int aSum = (a.first + a.second) ;
        int bSUm = (b.first + b.second) ;

        return bSUm  < aSum;
    });

    int ans = 0 ;
    int flip = 0 ;
    for(auto [ x , y ] : v) {
        if(flip % 2 == 0) {
            ans += x - 1 ;
        } else {
            ans -= y - 1 ;
        }

        flip = !flip;
    }

    cout << ans << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
