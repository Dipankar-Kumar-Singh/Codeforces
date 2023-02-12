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
    int ans = 0 ; 
    int m , n , p ; cin >> m >> n >> p ;
    p-- ;

    vector<vector<int>> v(m,vector<int>(n)) ; 
    for(auto &r : v) for(auto &e : r ) cin >> e ; 

    for(int  i = 0 ; i < n; i++)
    {
        int curr = v[p][i] ;
        int mx = - 1; 

        for(int k = 0 ; k < m ; k++)
        {
            mx = max(v[k][i],mx) ;
        }

        if(curr < mx)
        {
            ans += mx - curr ;
        }
    }

    print(ans) ;
}

signed main(){  FAST    TestCases    solve() ; }