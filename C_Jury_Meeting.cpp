#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(CURRENT_CASE = 1 ; CURRENT_CASE <=  TOTALTC ; CURRENT_CASE++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int CURRENT_CASE = 1 ;

const int MOD = 998244353 ;
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    sort(begin(v), end(v));

    if (v[n - 1] - v[n - 2] > 1)
    {
        cout << 0 << nl;
        return;
    }

    int total = fac[n];
    cerr << total << nl;

    if (v[n - 1] - v[n - 2] == 1)
    {
        cout << fac[n - 1] * (n - 1) << nl;
    }

    else
    {
        cout << fac[n] << nl;
    }


    
}

signed main()
{
    FAST     pre();
    TestCases     solve();
}


