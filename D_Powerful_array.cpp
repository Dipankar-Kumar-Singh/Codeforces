// Am I aggressive enough ?? 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

int const N = 400 ;



signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n ; cin >> n ;
    int q ; cin >> q ;  
    vector<int> v(n) , count(1'000'001);
    for(auto &x : v ) cin >> x  ;

    int sum = 0 ;

    vector<array<int,3>> quries(q) ;
    for(int i = 0 ; i < q ; i++){ 
        auto &[ l , r , t ] = quries[i] ;
        cin >> l >> r ; 
        l-- ; r-- ; 
        t = i ; 
    }

    sort(begin(quries),end(quries),[&](array<int,3> &a , array<int,3> &b) -> bool { 
        int B1 = a[0] / N ;
        int B2 = b[0] / N ;

        if( B1 == B2 ) {
            return a[1] < b[1] ;
        }

        return B1 < B2 ; 
    });

    auto add = [&](int id) {
        if(id == -1 or id >= n) return ;
        int x = v[id] ;
        int old_contribution = count[x] * count[x] * x ;
        sum -= old_contribution ; 
        count[x]++ ;
        int new_contribution = count[x] * count[x] * x ;
        sum += new_contribution ;
    };
    auto sub = [&](int id) {
        if(id == -1 or id >= n ) return ;
        int x = v[id] ;
        int old_contribution = count[x] * count[x] * x ;
        sum -= old_contribution ; 
        count[x]-- ;
        int new_contribution = count[x] * count[x] * x ;
        sum += new_contribution ;
    };

    vector<int> ans(q) ;

    int ml = -1 , mr = -1 ;
    for(auto &[ l , r , t ] : quries) { 
       
        while( ml < l ) sub(ml++)  ;
        while( ml > l ) add(--ml)  ;
        while( mr > r ) sub(mr--) ;
        while( mr < r ) add(++mr) ; 

        ans[t] = sum ;
    }

    for(int &x : ans ) cout << x << nl ;

}