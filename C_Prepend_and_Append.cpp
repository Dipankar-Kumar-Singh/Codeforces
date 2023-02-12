#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n ; cin >> n ;
    string s ; cin >> s ;

    int l = 0 , r = n - 1 ;

    while (s[l] != s[r] and l < r)
    {
        l++ ;
        r-- ;
    }

    cout << r - l + 1 << nl ;
    
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
