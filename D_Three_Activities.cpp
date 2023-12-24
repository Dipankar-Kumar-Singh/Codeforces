#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n; cin >> n ;
    vector<pair<int,int>> a(n) , b(n) , c(n) ;

    map<int,int> ma , mb , mc ;

    for(int i = 0 ; i < n; i++){
        int x; cin >> x ; 
        a[i] = {x , i} ;
        ma[i] = x ;
    }

    for(int i = 0 ; i < n; i++){
        int x; cin >> x ; 
        b[i] = {x , i} ;
        mb[i] = x ;
    }

    for(int i = 0 ; i < n; i++){
        int x; cin >> x ; 
        c[i] = {x , i} ;
        mc[i] = x ;
    }

    sort(all(a),greater<>()) ;
    sort(all(b),greater<>()) ;
    sort(all(c),greater<>()) ;

    int ans = -1 ;

    for(int i = 0 ; i < min(n,(int)20) ; i++){

        for(int j = 0 ; j < min(n,(int)20) ; j++){

            for(int k = 0 ; k < min(n,(int)20) ; k++){

                auto& [x , i1] = a[i] ;
                auto& [y , i2] = b[j] ;
                auto& [z , i3] = c[k] ;

                if(i1 != i2 && i2 != i3 && i3 != i1){
                    ans = max(ans , (x + y + z)) ;
                }
            }
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
