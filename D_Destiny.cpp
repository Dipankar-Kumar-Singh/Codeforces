// Am I aggressive enough ?? 

#include <bits/stdc++.h>
#include <ext/random>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

int const N = 500 ; // Sqrt(3e5) 3e5 --> from Input 
// mt19937 --  mersenne_twister_engine seeded with rd()
__gnu_cxx::sfmt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); 
// uniform random distribution

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n ;
    int q ; cin >> q  ;
    vector<int> v(n) , count(n + 1)  ;
    for(auto &x : v ) cin >> x ; 

    vector<array<int,4>> quries(q) ;
    for(int i = 0 ; i < q ; i++) {
        auto &[l, r, k, time] = quries[i] ;
        cin >> l >> r >> k ; 
        l-- ; r-- ; 
        time = i ; 
    }

    sort(all(quries),[&](array<int,4> &a , array<int,4> &b)->bool { 
        auto &[ l1 , r1 , k1 , t1 ] =  a ;
        auto &[ l2 , r2 , k2 , t2 ] =  b ;

        int BLOCK_1 = l1 / N ; 
        int BLOCK_2 = l2 / N ;

        if(BLOCK_1 == BLOCK_2 ) { 
            return r1 < r2 ;
        }

        return BLOCK_1 < BLOCK_2  ;

    });


    function<void(int)> add = [&](int id) -> void { 
        if(id == -1 ) return;
        count[v[id]]++ ;
    };

    function<void(int)> sub = [&](int id) -> void { 
        if(id == -1 ) return ;
        count[v[id]]-- ;
    };

    
    vector<int> ans(q) ;

    int ml = -1 , mr = -1 ; 

    for(auto [l , r , k , time ] : quries ) { 
        while( ml < l ) sub(ml++) ;
        while( ml > l ) add(--ml) ;
        while( mr > r ) sub(mr-- );
        while( mr < r ) add(++mr) ;

        int best = numeric_limits<int>::max()  ;

        for(int guess = 0 ; guess < 100 ; guess++ ) {
            
            int range_len = (r - l + 1) ; 
            int random_index = (rng() % range_len) + l ;
            int val = v[random_index] ;
            int cutOff = range_len / k ;
            if(count[val] > cutOff ) { 
                best = min( best , val ) ;
            }
        }

        if(best == numeric_limits<int>::max()) best = -1 ; 
        ans[time] = best ;
    }


    for(auto x : ans ) cout << x << nl ;


}