#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;


signed main()
{
    FAST 
    t_case
    {
        int n , m , r , c ; cin >> n >> m >> r >> c ;

        vector<string> v(n) ;
        for(auto &s : v)
        {
            cin >> s ;
        }

        // for(auto &s : v) cout << s << "\n" ; 
        // cout << "\n" ;

        vector<pair<int,int>> cord ;

        for(int i  = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(v[i][j] == 'B') cord.push_back({i+1,j+1}) ;
            }
        }

        if(cord.empty()) 
        {
            cout << -1 << "\n"; continue ;
        }

        int p1 = 0 , p2 = 0  ;

        for(auto &[x,y] : cord)
        {
            if(x==r and y==c)
            {
                p1 = 1 ;
            }

            if(x == r or y == c){ p2 = 1 ; }
        }

        if(p1 or p2)
        {
            if(p1)
            {
                cout << 0 << "\n" ; 
                continue ;
            }

            if(p2)
            {
                cout << 1 << "\n" ; 
                continue ;
            }
        }

        else cout << 2 << "\n" ;
    
                                       
                                       
    }
}

