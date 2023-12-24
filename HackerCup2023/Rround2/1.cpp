#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
#include"/home/dk/debugging.h"

//  g++ 1.cpp && ./a.out

int n , m ;
vector<vector<int>> vis , vis2 ; 
vector<string> v ;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

set<pair<int,int>> seats ;
bool ok(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

set<pair<int,int>> forest ;

void dfs(int x , int y ){
    
    if(!ok(x,y)) return ;
    
    if(vis[x][y]) return ; 
    vis[x][y] = 1 ;

    forest.insert({x,y}) ;

    for(int i = 0 ; i < 4 ; i++) {
        int newX = x + dx[i]; 
        int newY = y + dy[i];

        if(!ok(newX,newY)) 
            continue;  

        if(v[newX][newY] == '.') 
            seats.insert({newX,newY}) ;

        if(vis[newX][newY])
            continue;
        
        v[newX][newY] ;

        if(v[newX][newY] == 'W') {
            dfs(newX,newY) ;
        }
    }
}

void dfs2(int x , int y ){
    if(vis2[x][y]) return ; 
    vis2[x][y] = 1 ;

    forest.insert({x,y}) ;

    for(int i = 0 ; i < 4 ; i++) {
        int newX = x + dx[i]; 
        int newY = y + dy[i];

        if(!ok(newX,newY)) continue;  
        if(v[newX][newY] != 'W') seats.insert({newX,newY}) ;

        if(vis2[newX][newY]){
            continue;
        }

        if(v[newX][newY] == 'W') {
            dfs2(newX,newY) ;
        }
    }
}

// void spreadDFS(int x , int y) {
//     for(int i = 0 ; i < 4 ; i++) {
//         int newX = x + dx[i]; 
//         int newY = y + dy[i];
//         if(!ok(newX,newY)) continue;  
//         if(v[newX][newY] == 'W') {
//             dfs2(newX,newY) ;
//         }
//     }
// }


void solve(int& __case__)
{   
    cout << "Case #" << __case__ << ": " ;

    cin >> n >> m ; 
    vis = vector<vector<int>> (n  + 1 , vector<int> (m + 1)) ;
    v = vector<string>(n) ;
    for(auto &s : v) cin >> s ;


    int best_possible = 0 ;
    auto viscopy = vis ;

    vis2 = viscopy ;

 
    for(int i = 0 ; i < n;  i++){
        for(int j = 0 ; j < m ; j++){
            if(!ok(i,j)) continue;
            if(vis[i][j]) continue;
            if(v[i][j] == 'W') {

                forest.clear() ;
                seats.clear() ;

                dfs(i,j) ;

                int black_req = 0 ;
                pair<int,int> paint = {0,0} ;

                // for(auto& [x,y] : seats) {
                //     // if(v[x][y] != 'B') { 
                //     //     black_req++ ;
                //     //     if(v[x][y] == '.') 
                //     //         paint = {x,y} ;
                //     // }
                // }

                // if(black_req == 1 ) {
                //     best_possible = max(best_possible , (int)forest.size()) ;

                //     // auto [x , y] =  paint ;
                //     // auto orgChar = v[x][y] ;
                //     // v[x][y] = 'B' ;
                //     // forest.clear() ;
                //     // seats.clear() ;

                //     // vis2 = viscopy ;
                //     // spreadDFS(x,y) ;

                //     // best_possible = max(best_possible , (int)forest.size()) ;
                //     // v[x][y] = orgChar ;
                // }

                // forest.clear() ;
                // seats.clear() ;
            }
        }
    }

    cout << best_possible << nl ;

    // if(best_possible == 0 ) {
    //     cout << "NO" << nl ;
    // } else {
    //     cout << "YES" << nl ;
    // }

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
