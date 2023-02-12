#include <bits/stdc++.h>
using namespace std;

    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
    // Keep Going, Never Give up .

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;


const int MOD = 1e9 + 7;
const int  N = 10;
 
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

signed main() { 
    FAST  
    pre() ; 

    int n ; cin >> n;
    int res = n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
    int ans = res / fac[5] ;
    ans *= res ;
    cout << ans ;
}
