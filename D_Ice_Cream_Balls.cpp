#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


__uint128_t nc2(int n){
    return ( __uint128_t(n) * (n - 1)) / __uint128_t(2) ;
}

void solve(int& __case__)
{
    int n ;  cin >> n ;


    int l = 0 , r = 1e10 ; 
    while(r - l > 1 ){
        int mid = midpoint(l,r) ;
        __uint128_t res = nc2(mid)  ;
        if(res <= __uint128_t(n)){ l = mid ;}
        else r = mid ;
    }

    int lC2 = nc2(l) ;


    if(nc2(l) == n){
        cout << l << nl ;
    } else {
        int res = nc2(l)  ;
        int needed = n - res ;
        int ans = l + needed ;
        cout << ans << nl ;
    }

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;    
    // cout << "19C2   = " << (long long)nc2(19) << nl ;

    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
