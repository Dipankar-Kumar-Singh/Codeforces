// Am I aggressive enough ?? 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n; cin >> n ;
    int a {0} , b {0} , c {0} , d {0} ; 
    while(n--){
        int x , y ; 
        cin >> x >> y ;
        if(x > 0 ) a++ ; 
        if(x < 0 ) b++ ; 
        if(y > 0 ) c++ ; 
        if(y < 0 ) d++ ;
    }

    if(a == 0 or b == 0 or c == 0 or d == 0 ) {
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