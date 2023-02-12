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
    int a, b , c ; cin >> a >> b >> c ;

    bool c1 = a + b == c;
    bool c2 = b + c == a;
    bool c3 = a + c == b;

    if(c1 or c2 or c3)
    {
        cout << "YES" << nl ;
    }

    else cout << "NO" << nl ;
}

signed main(){  FAST    TestCases    solve() ; }