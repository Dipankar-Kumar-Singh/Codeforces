    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

const int N = 1e7;
vector<int> lp(N + 1);
vector<int> pr;

void preCompute()
{
    // Time : O ( n )  -----> Linear Sieve  
    // CP-Algorithm : https://cp-algorithms.com/algebra/prime-sieve-linear.html

    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j){
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
}

set<int> factors(int num)
{
    set<int> factors ;
    while(num)
    {
        if(num <= 1) break ;
        factors.insert(lp[num]) ;
        num /= lp[num] ;
    }
    return factors ;
}

void solve()
{
    int a , b ;
    cin >> a >> b ;

    if (a > b)  swap(a, b);

    if(abs(a-b) == 1 ) {
        cout << -1 << nl;
        return ;
    }

    if(gcd( a , b ) != 1) {
        cout << 0 << nl ;
        return ;
    }

    int diff = b - a ;
    int ans = numeric_limits<int>::max() ;

    for(auto x : factors(diff))
    {
        int AA = ((a / x) * x) + x;
        ans = min(ans , AA - a ) ;
    }

    cout << ans << nl ;
}

signed main() { FAST preCompute() ; TestCases solve(); }
