#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{

    int n ; cin >> n ; 
    vector<int> v(n) ; for(int &i : v ) cin >>  i ;


    int ans = 0 ;

    for(int i = 1 ; i + 1< n ; i++ )
    {
        if(v[i]>v[i-1] and v[i]>v[i+1])
        {
           int next = (i+2<n ? v[i+2] : 0 ) ;
           int now = v[i] ;
           int put = max(next,now) ;

           v[i+1] = put ;
           ans++ ;
        }
    }

    
    cout << ans << "\n" ;
    for(auto &x : v) cout << x << " " ;
    cout << "\n" ;



}

signed main()
{
    FAST 
    t_case
    {
     
        solve() ;

                                       
    }
}

