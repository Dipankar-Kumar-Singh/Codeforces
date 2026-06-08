/*
 *  Title : D - Repeatedly Repainting
 *  URL   : https://atcoder.jp/contests/abc460/tasks/abc460_d
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

    vector<vector<bool>> vec(n,vector<bool>(m)) ;
    for(auto &row : vec){
        for(std::vector<bool>::reference item: row){
            char c ; cin >> c ; 
            item = c == '#' ;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases = 1;
    cin >> testCases;             // comment out for single-test problems
    for (int tc = 1; tc <= testCases; tc++)
        solve(tc);

    return 0;
}
