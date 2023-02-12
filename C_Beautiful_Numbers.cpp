#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1000000007;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int a{} , b{} , n{} ;
bool is_good(int num);


// IMPORTANT : NOTE : DO INSITIALIZE FACTS....
int const N = 1e6 + 10 ;
long long fact[N + 1];
int modulo = 1000000007 ; 

long long binpow(long long val, long long deg, long long mod) {
    if (!deg) return 1 % mod;
    if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
    long long res = binpow(val ,deg >> 1, mod);
    return (res*res) % mod;
}
void initfact() {
    // IMPORTANT : NOTE : DO INSITIALIZE ....
    fact[0] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1] * i);
        fact[i] %= modulo;
    }
}
long long nCr_mod_Prime(int n, int i) {
    long long res = fact[n];
    long long div = fact[n-i] * fact[i];
    div %= modulo;  div = binpow(div, modulo - 2, modulo);
    return (res * div) % modulo;
}

 
bool check(long long val) {
    while (val > 0) {
        if (val % 10 == a || val % 10 == b) {
            val /= 10;
        } else return false;
    }
    return true;
}

signed main()
{
    FAST 

    initfact() ;

    // int a , b , n ; 
    cin >> a >> b >> n ;
    int total = 0 ;

    for(int i = 0 ; i <=n ; i++ )
    {
        int rem = n - i ;
        char ac = '0' + a  , bc = '0' + b ;

        int a_sum = a * i  ;
        int b_sum = b * (n-i) ;

        int sm = a_sum  + b_sum ;

    
        if(check(sm))
        {
            // excilent number .... 
            int nCi  = 0 ;
            nCi = nCr_mod_Prime(n,i) ;
            total = (total%MOD +  nCi%MOD)%MOD ;
        }
    }

    cout << total << "\n" ;

    
}

