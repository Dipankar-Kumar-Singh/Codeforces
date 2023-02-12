#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int totalLTC ; cin >> totalLTC ; for(_case = 1 ; _case <=  totalLTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int const MOD = 998244353  ;
const int N = 3e5 + 1e2;
vector<bool> is_prime(N+1, true);
void calculate()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

void solve()
{
    int ans = 0 ;
    int n , m ; cin >> n >> m ;

    int total = 1 ; 
    int pr = 1 ;
    int curr = 1 ;
    
    for (int i = 1 ; i <= n; i++)
    {
        total *=  m % MOD  ;          total %= MOD ;

        if(is_prime[i])  curr =  curr * i ;

        if(curr > m) 
        {
            ans += total ;              ans %= MOD ;
            continue;
        }

        int range = m / curr;           range %= MOD;
        pr =  pr *range ;               pr %= MOD ;

        int x = (total - pr) ;          if(x < 0) x += MOD ; x %= MOD ;
        ans += x ;                      ans %= MOD ; 
       
    }

    cout << ans << nl ;

}
signed main(){   FAST  calculate() ;    solve() ;  }



