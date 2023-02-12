#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

void solve()
{
    int n ; int k ; cin >> n >> k ;

    vector<bitset<32>> v(n) ;

    for(auto &x : v)
    {
        int t  ; cin >> t ;
        x = bitset<32>(t) ;
    }

    bitset<32> ans ; 
    

    for(int  col = 0 ;  col < v[0].size() ;  col++)
    {
        int one = 0 , zero = 0 ;

        for(int row = 0 ; row < v.size( ) ; row++ )
        {
            if(v[row][col]) one++ ;
            else zero++ ;
        }
        ans[col] = (one > zero ? 1 : 0 ) ;
    }

    int res = ans.to_ullong() ;
    cout << res << "\n" ;

}


signed main()
{
    FAST 
    t_case
    {
        
        solve( ) ;
                                                               
    }
}

