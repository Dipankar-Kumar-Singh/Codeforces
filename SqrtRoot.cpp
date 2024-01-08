// Am I aggressive enough ?? 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 



int const BLOCK_SIZE = 300 ;
vector<Query> queries;
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

void Mo_algo(){

    function<void(int)> add = [&](int id) -> void {

    };

    function<void(int)> sub = [&](int id) -> void {

    };

    vector<int> ans(queries.size()) ;

    int ml = 0 , mr = -1 ;
    for(auto &[ l , r , id ] : queries) {
        while( ml < l ) sub(ml++) ;
        while( ml > l ) add(--ml) ;
        while( mr > r ) sub(mr-- );
        while( mr < r ) add(++mr) ;

        ans[id] = 0 ;
    }

    for(auto &x : ans) 
        cout << x << nl ; 
}

signed main(){

}