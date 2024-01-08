/* 
            ~~~~~~~~~~~~{ after 1 Year of Pause, I am back : ) }~~~~~~~~~~ 
    I will fall .... Yep free fall  : ) .... I will go up again ! ... 
    Always proud of my efforts in past - 2nd Year(Start of cp) -- 3rd Year(till 1st sem)
    Last 6 month of college ... want to look back and smile : ) , No Regret 
*/

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"


signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    int t = 1 ;
    vector<vector<int>> v(n,vector<int>(n)) ;
    vector<pair<int,char>> st ;

    v[n/2][n/2] = -1 ;

    st.push_back({1,'L'}) ;

    auto giveNextDir =[](char c) -> char {
        if(c == 'U') return 'R' ;
        if(c == 'R') return 'D' ;
        if(c == 'D') return 'L' ;
        if(c == 'L') return 'U' ;
        return 'D' ;
    };

    int x =(n/2) , y = (n/2) - 1 ;

    v[x][y] = t++ ;

    


    while (t < (n * n) ){
        
        char dir = giveNextDir(st.back().second) ;
        int base = st.back().first ;

        if(dir == 'R' or dir == 'L') base++ ;

        st.push_back({base,dir}) ; 

        while(base--) {
            if(dir == 'U') {
                x-- ;
            } else if (dir == 'D' ) {
                x++ ;
            } else if( dir == 'L') {
                y-- ;
            } else if( dir == 'R') {
                y++ ;
            }

            if(t >= n * n ) {
                break;
            }

            v[x][y] = t++ ;
        }
    }

    // for(auto r : v) {
    //     for(auto c : r) cout << c << " "  ;
    //     cout << nl ;
    // } cout << nl << nl;

    for(int i = 0 ; i < n;  i++){
        for(int j = 0 ; j < n ; j++){
            if(v[i][j] == -1) {
                cout <<  'T' << ' ' ;
            } else {
                cout << v[i][j] << " " ;
            }
        } cout << nl ;
    }


}

/*
            ██████╗ ██╗██████╗  █████╗ ███╗   ██╗██╗  ██╗ █████╗ ██████╗ 
            ██╔══██╗██║██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝██╔══██╗██╔══██╗
            ██║  ██║██║██████╔╝███████║██╔██╗ ██║█████╔╝ ███████║██████╔╝
            ██║  ██║██║██╔═══╝ ██╔══██║██║╚██╗██║██╔═██╗ ██╔══██║██╔══██╗
            ██████╔╝██║██║     ██║  ██║██║ ╚████║██║  ██╗██║  ██║██║  ██║
            ╚═════╝ ╚═╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
*/                                                          
