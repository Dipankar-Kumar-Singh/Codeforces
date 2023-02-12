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
    vector<int> v(n) ; 
    v.front() = 1 ;
    for(int i = 1 , ct = n ; i < n ; i++)
    {
        v[i] = ct-- ;
    }

    for(auto x : v) cout << x << " " ; cout << nl ;

    
}

signed main(){  FAST    TestCases    solve() ; }