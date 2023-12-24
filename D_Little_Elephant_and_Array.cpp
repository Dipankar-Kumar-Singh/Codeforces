#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// Practice Mo's Algorithm

int const BLOCK_SIZE = 700 ;
bool comp(tuple<int, int, int> &p, tuple<int, int, int > &q){
    
    auto& [ l1 , r1 , id1] = p ;
    auto& [ l2 , r2 , id2] = q ;

    int a_block = l1 / BLOCK_SIZE ;
    int b_block = l2 / BLOCK_SIZE ;

    if (a_block == b_block)
        return ((a_block & 1) ?  r1 < r2 : r1 > r2 ); // simple r1 < r2 will also work , but this one has better real world time complexity
    return a_block < b_block ;
}

void solve(int& __case__)
{
    int n ; cin >> n;
    int q ; cin >> q ; 

    vector<int> v(n) ;
    for(int &x : v) cin >> x ;

    int MAXN = n + 10 ;

    vector<tuple<int,int,int>> queries(q) ;
    for (int i = 0; i < q; i++)    {
        auto &[l, r, id] = queries[i];
        cin >> l >> r;
        l--, r--;
        id = i;
    }

    // const BLOCK_SIZE --> 
    // Compiler will perform a lot better : if BLOCK_SIZE is CONST 
    // MAKE IT A NUMBER don't calcualte on runtime .. how to fix a number(by seeing constraints / limits ) 
    // BLOCK_SIZE = sqrt(n + 0.0) + 1 ;
    sort(all(queries), comp);

    vector<int> m(MAXN);
    int goodNumbers =  0 ;

    auto add = [&](int x) {
        if(x > MAXN) return ;
        if(m[x] == x ) goodNumbers-- ;
        m[x]++ ;
        if(m[x] == x) goodNumbers++ ;
    };

    auto sub = [&](int x){
        if(x > MAXN) return ;
        if(m[x] == x ) goodNumbers-- ;
        m[x]-- ;
        if( m[x] == x ) goodNumbers++ ;
    };

    int ml = 0 , mr = -1 ;

    vector<int> ans (q) ;

    for(auto &[ l , r , id ] : queries ) {
        while (ml < l)
        {
            sub(v[ml]) ;
            ml++ ;
        }
        while(ml > l ){
            ml-- ;
            add(v[ml]) ;
        }
        while(mr > r) {
            sub(v[mr]) ;
            mr-- ;
        }
        while(mr < r ) {
            mr++ ;
            add(v[mr]) ;
        }
        
        ans[id] = goodNumbers ; 
    }

    for(auto &x : ans ) cout << x << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    // cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
