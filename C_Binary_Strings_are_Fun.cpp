    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 
int __case__ = 1 ;
int const MOD = 998244353 ;

void solve()
{
    int n ; cin >>  n;
    string s ; cin >> s ;
    int curr = 1 , ans = 1 ; 
    for(int i = 1 ; i < n; i++)
    {      
        curr = (s[i] == s[ i- 1 ] ? 2 * curr : 1) ;    curr  %= MOD ; 
        ans += curr ; ans %= MOD ;
    }

    cout << ans << nl ;
}

signed main() { FAST TestCases solve(); }
