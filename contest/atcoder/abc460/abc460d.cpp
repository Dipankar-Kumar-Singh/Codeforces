/*
 *  Title : D - Repeatedly Repainting
 *  URL   : https://atcoder.jp/contests/abc460/tasks/abc460_d
 */
#include <bits/stdc++.h>
using namespace std;

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

struct Point{ 
    int x; 
    int y;
    int generation;
};

void solve(int& tc) {
    int n , m ; 
    cin >> n >> m ;

    vector<vector<bool>> vec(n, vector<bool>(m));
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<Point> q ;

    function get_neighbours = [&](int i, int j) -> vector<pair<int,int>> {
        vector<pair<int,int>> neighbours = {}; 
        neighbours.reserve(8);

        for (const auto& [dx, dy] : dirs) {
            if((i + dx) < 0 or (i + dx) >= n or (j + dy) >=m or (j + dy) < 0) continue;
            neighbours.emplace_back(i + dx, j + dy);
        }
        return neighbours ; 
    };

    int black_count = 0 ; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            char c ; cin >> c ; 
            vec[i][j] = (c == '#') ;
            if(vec[i][j] == true) {
                q.push(Point{i,j,0});
                vis[i][j] = 0; 
                black_count++ ; 
            }
        }
    }

    if(black_count == n * m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << "." ;
            } cout << "\n";
        }
        return ;
    }

    while(q.size()){
        auto [x,y, gen] = q.front();
        q.pop();

        for (auto& [nx, ny] : get_neighbours(x, y)) {
            if (vis[nx][ny] != -1) continue;
            vis[nx][ny] = gen + 1 ; 
            q.push({nx, ny, vis[nx][ny]});
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == - 1 or vis[i][j] % 2) cout << "." ; 
            else cout << "#" ;
        } cout << "\n" ;
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
