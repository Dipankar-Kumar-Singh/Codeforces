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

constexpr array<pair<int, int>, 8> dirs{{
    {-1, -1}, {-1, 0}, {-1, 1}, // ↖ ↑ ↗
    { 0, -1},           { 0, 1}, // ←   →
    { 1, -1}, { 1, 0}, { 1, 1}  // ↙ ↓ ↘
}};



void solve(int& tc) {
    int n , m ; 
    cin >> n >> m ;

    vector<vector<bool>> vec(n, vector<bool>(m));
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<pair<int,int>> q ;

    function get_neighbours = [&](int i, int j) -> vector<pair<int,int>> {
        vector<pair<int,int>> neighbours = {}; 
        neighbours.reserve(8);

        for (const auto& [dx, dy] : dirs) {
            neighbours.emplace_back(i + dx, j + dy);
        }
        return neighbours ; 
    };


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            char c ; cin >> c ; 
            vec[i][j] = c == '#' ;
            if(vec[i][j] == true) q.push({i,j});
        }
    }


    while(q.size()){
        auto [x,y] = q.front();
        q.pop();

        for (auto [nx, ny] : get_neighbours(x, y)) {
            if(vis[nx][ny] != -1) continue ; 

            if(vis[1] == )
        }
    }
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
