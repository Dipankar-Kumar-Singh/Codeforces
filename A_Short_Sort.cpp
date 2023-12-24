#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{   
    string s ; cin >> s ; 
    string ss = s ; 

    string t = "abc" ;

    if(s == t) { 
        cout << "YES" << nl ;
        return ;
    }

    swap(ss[0] , ss[1]) ;
    if(ss == t ) {
        cout << "YES" << nl ;
        return ;
    }

    ss = s ;
    swap(ss[1],ss[2]) ;

    if(ss == t ) {
        cout << "YES" << nl ;
        return ;
    }

    ss = s ;
    swap(ss[0],ss[2]) ;
    if(ss == t ) {
        cout << "YES" << nl ;
        return ;
    }

    cout << "NO" << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
