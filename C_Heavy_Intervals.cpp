#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n ; cin >> n; 
    vector<int> a(n) , b(n) , c(n) ;
    for(int &x : a) cin >> x  ;
    for(int &x : b) cin >> x  ;
    for(int &x : c) cin >> x  ;

    sort(all(a)) ; sort(all(b)) ; sort(all(c)) ;

    vector<int> len(n) ; 
    for(int i = 0 ; i < n ; i++){
        len[i] = b[i] - a[i]  ;
    }

    sort(all(len),greater<int>()) ;

    long long ans = 0 ; 
    for(int i = 0 ; i < n ; i++){
        ans += len[i] * c[i] ; 
    }

    cout << ans << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}