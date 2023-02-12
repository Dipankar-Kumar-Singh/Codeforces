#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

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

signed main(){   
    FAST    pre()   ;      
    
    int n ; cin >> n;
    int k ; cin >> k ;

    vector<int> endpoints ;
    map<int,int> active ;

    for(int i = 0 ; i < n; i++)
    {
        int l , r ; 
        cin >> l >> r;

        active[l]++ ;
        active[r+1]-- ;

    }

    for(auto [x,fr] : active) endpoints.push_back(x) ;

    int curr = 0 ;
    int ans = 0 ;

    for(int i = 0 ; i + 1 < endpoints.size() ; i++)
    {
        curr += active[endpoints[i]] ;
        int sz = endpoints[i+1] - endpoints[i]  ;

        ans += choose(curr, k) * sz;
        ans %= MOD ;
    }

    cout << ans << endl ; 
}



