#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"
signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n , q ; 
    cin >> n >> q ;

    // 1,0   2,0 ,   3,0 .......

    vector<pair<int,int>> head = {{1,0}};


    while(q--){
        int t ; cin >> t ; 
        if(t == 1){
            char c; cin >> c ;
            auto [x,y] = head.back() ;
            if(c == 'U') {
                y++ ; 
            } else if(c == 'D'){
                y-- ;
            } else if( c == 'L'){
                x-- ;
            } else if( c == 'R'){
                x++ ;
            }
            head.push_back({x,y}) ;
        } 
        else if( t == 2 ){
            int p ; cin >> p ;
            int t = head.size() - 1 ;

            if(p - t <= 0){
                int extraMoves = p - t ;
                int delta = p - t;
                delta = -(delta) ;

                auto [x, y] = head[delta + 1];
                cout << x << " " << y << nl ;

                // head[]
            } else {
                cout << p - t << " " << 0 << nl ;
            }
        }
    }


    
}

