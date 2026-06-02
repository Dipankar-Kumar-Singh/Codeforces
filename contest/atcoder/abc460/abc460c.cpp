/*
 *  Title : C - Sushi
 *  URL   : https://atcoder.jp/contests/abc460/tasks/abc460_c
 */
#include <bits/stdc++.h>
using namespace std;

#define int      long long
#define all(x)   begin(x), end(x)
#define nl       '\n'

#ifdef CPH
    #include "/Users/dk/personal/Codeforces/debugging.h"
    template <class T> void _dbg(T x) { cerr << x << endl; }
    template <class T, class... R> void _dbg(T x, R... r) { cerr << x << " | ", _dbg(r...); }
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", _dbg(__VA_ARGS__)
#else
    #define debug(...)
#endif

void solve(int& tc) {

    int n , m ; 
    cin >> n >> m ; 

    vector<int> a(n), b(m); 
    for(auto &x : a) cin >> x ; 
    for(auto &x : b) cin >> x ; 

    set<pair<int,int>> s ; 
    for(int i = 0 ; i < m ; i++){
        s.insert({b[i],i}) ;
    }
    int matched = 0; 
    std::sort(std::begin(a),std::end(a)) ;

    for(int& x : a){
        if (empty(s)) break;

        auto it = s.begin() ;
        auto [ match, index ] = *it ;
        debug(x , match, index) ;

        if(match > 2 * x) continue;
        s.erase(it) ; 
        matched++ ; 
    }

    cout << matched << "\n" ;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;             // comment out for single-test problems
    for (int tc = 1; tc <= testCases; tc++)
        solve(tc);

    return 0;
}
