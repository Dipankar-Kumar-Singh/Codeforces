#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;

int test = 0 ;

const int MOD = 1e9 + 7;
const int  N = 1e6 + 5;
 
int fac[N], ifac[N];
 
void pre() { 
    fac[0] = ifac[0] = ifac[1] = 1;
    for (int i = 1; i < N; i++) { 
        fac[i] = i * fac[i - 1] % MOD;
    }
    for (int i = 2; i < N; i++) { 
        ifac[i] = ifac[MOD % i] * (MOD - MOD / i) % MOD;
    }
    for (int i = 1; i < N; i++) { 
        ifac[i]= ifac[i] * ifac[i - 1] % MOD;
    }
}
 
int choose(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return fac[n] * ifac[r] % MOD * ifac[n - r] % MOD;
}


void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 
    vector<int> a(n) ;
    a[0] = v[0] ;

    for(int i = 1 ; i < n ; i++)
    {
        int x = a[i - 1] + v[i];
        int y = a[i - 1] - v[i];

        if(x >= 0 and y >= 0 and x!=y )
        {
            cout << -1 << nl  ; 
            return ; 
        }

        a[i] = max(x,y) ;
    }

    for(auto x : a ) cout << x << " " ; cout << nl ;
}

signed main(){  FAST    TestCases    solve() ; }