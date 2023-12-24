#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/Code/debug/debugging.h"

void solve(int& __case__)
{
    vector<int> v(3) ;
    for(auto &x : v) {
        cin >> x ;
    }

    sort(all(v)) ;
    if(v[1] + v[2] >= 10){ 
        cout << "YES" << nl ;
    } else {
        cout << "NO" << nl ;
    }

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
