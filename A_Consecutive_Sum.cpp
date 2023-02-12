#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;


void solve()
{

    int n ; cin >> n ;
    int k ; cin >> k ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ;

    map<int,int> m ;
    set<int> s ;

    for(int i = 0 ; i < n ; i++)
    {
        m[i%k] = max(m[i%k],v[i]) ;
        s.insert(i%k) ;
    } 

    int ans = 0 ;

    for(auto x : s) 
    {
        ans += m[x] ;
    }

    cout << ans << nl ;


}

signed main(){  FAST    TestCases    solve() ; }