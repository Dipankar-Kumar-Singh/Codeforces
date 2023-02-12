#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

// // IMPORTANT : NOTE : DO INSITIALIZE FACTS PRE CAL FUNCTION....
int N = 1e6 + 1e4;
int modulo = 998244353 ; 
vector<long long> fact(N+10,1) ; 
vector<long long> invfact(N+10,1) ;

long long binpow(long long val, long long deg, long long mod) {
    if (!deg) return 1 % mod;
    if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
    long long res = binpow(val ,deg >> 1, mod);
    return (res*res) % mod;
}

void init() {
    // IMPORTANT : NOTE : DO INSITIALIZE ....
    fact[0] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1] * i);
        fact[i] %= modulo;
    }
    invfact[N] = binpow(fact[N], modulo - 2, modulo) ;
    for (int i = N - 1; i > 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % modulo;
}

long long C(int n , int r)
{
    if(r>n) return 0 ;
    long long ans  = fact[n] ;
    ans *= invfact[r] ;   ans%=modulo ;
    ans *= invfact[n-r] ; ans%=modulo ;
    return ans ;
}

long long nCr_mod(int n, int i) {
    long long res = fact[n];
    long long div = fact[n-i] * fact[i];
    div %= modulo;  div = binpow(div, modulo - 2, modulo);
    return (res * div) % modulo;
}


void solve()
{
   
   int n ; cin >> n ;
   int k ; cin >> k ;
   vector<int> l(n)  , r(n) ; 
   for(int i = 0 ; i < n ;i++) cin >> l[i] >> r[i] ;

   sort(begin(l), end(l));
   sort(begin(r), end(r));

   // SWEEP LINE ALGORITHM 

   int i = 0 ; int j = 0 ;
   int on = 0 ;
   int ans = 0 ; 
   while(i<n and j<n)
   {
      if(l[i] <= r[j])
      {
         if(on>=k-1)
         {
            ans += C(on,k-1) ;
            ans%=modulo ;
         }

         i++ ;
         on++ ;
      }

      else
      {
         j++;
         on--;
      }
   }

   cout << ans << nl ;
   
}
signed main(){   FAST   init() ;   solve() ;  }



