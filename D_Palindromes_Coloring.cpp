#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        
        int n ; int k ; cin >> n >> k ;

        string st ; cin >> st ;

        map<char,int> m ;
        for(auto c : st ){ m[c]++ ; }
        int pair = 0 , single = 0 ;

        for(auto [x,y] : m)
        {
            pair += y/2 ;
            single  +=  (y&1) ;
        }

        int ans = 2*(pair/k) ;


        if( single + 2*(pair%k) >= k)
        {
            cout << ans + 1 ;
        }

        else cout << ans ;

        cout << "\n" ;
                             
    }
}

