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
     int n ; cin >> n ; 

    vector< pair < int ,int > >  v (n) ;
    for(auto &[x,y] : v) cin >> x >> y  ;

    sort(all(v)) ;
 
    int prev = min(v.front().first ,  v.front().second ) ;

    for(auto [a,b] : v)
    {
        // cout << a << " " << b << nl ;
        if(b < prev ) b = a ;
        prev = min(a ,b) ;
    }

    cout << prev ;

}

