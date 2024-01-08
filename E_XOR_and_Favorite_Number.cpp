// Am I aggressive enough ?? 
#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

int const BLOCK_SIZE = 300 ;
struct Query {
  int l, r, id;
};

bool comp(const Query &x, const Query &y) {
    if (x.l / BLOCK_SIZE != y.l / BLOCK_SIZE) {
        return x.l < y.l;
    } else {
        return ((x.l / BLOCK_SIZE) & 1) ?  x.r < y.r :  x.r > y.r;
    };
};

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , q , k ; 
    cin >> n >> q >> k ;

    vector<int> v(n) ; 
    for(auto &x : v) cin >> x ;

    vector<Query> queries(q);

    for(int i = 0 ; i < q; i++){
        auto &[l , r , id] = queries[i] ;
        cin >> l >> r ;
        id = i ;
    }

    sort(all(queries),comp) ;
    vector<int> seen( 2E6 ) ;

    vector<int> pre (n + 2,0) ; 
    for(int i = 1 ; i <= n ; i++) {
        pre[i] = (pre[i - 1] ^ v[i - 1]) ;
    }

    int result = 0 ;

    function add = [&](int id) -> void { 
        int x = pre[id] ;
        result += seen[ (x ^ k) ] ;
        seen[x]++ ;
    };

    function sub = [&](int id) -> void { 
        int x = pre[id] ;
        seen[x]-- ;
        result -= seen[ (x ^ k) ] ;
    };

    vector<int> ans(q) ;
    int ml = 0 , mr = -1 ;
    for(auto &[l , r , id] : queries) {
        while( ml < l - 1 ) sub(ml++) ;
        while( ml > l - 1 ) add(--ml) ;
        while( mr > r     ) sub(mr-- );
        while( mr < r     ) add(++mr) ;

        ans[id] = result ;
    }

    for(auto &x : ans ) 
        cout << x << nl ;
}