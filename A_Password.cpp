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


long long nCr(int n, int r)
{
    long long p = 1, k = 1;if (n - r < r) r = n - r;
    if (r != 0) {while (r) {p *= n; k *= r; long long m = gcd(p, k); p /= m; k /= m; n--; r--;}}
    else p = 1; return p ;
}


void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;     
    vector<int> marked(10) ;
    for(int i = 0;  i < n ; i++)
    {
        int x ; cin >>  x ;
        marked[x] = 1 ;
    }

    vector<int> use ;

    for(int i = 0 ; i < 10 ; i++) if(!marked[i]) use.push_back(i) ;

    n = use.size() ;

    ans = nCr(n,2)*6 ;

    cout << ans << nl ;
}

signed main(){  FAST    TestCases    solve() ; }