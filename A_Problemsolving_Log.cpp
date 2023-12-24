#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n ; cin >> n ;
    string s ; cin >> s ;

    map<char , int> mp ;
    for(char c : s) {
        mp[c]++ ;
    }

    int ans = 0 ;

    for(auto& [c , cnt] : mp) {
        if(cnt >= c - 'A' + 1) {
            ans++ ;
        }
    }

    cout << ans << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
