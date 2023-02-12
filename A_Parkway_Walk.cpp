#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
   int n ; cin >> n ; int m ; cin >> m ;
   vector<int> v (n) ; for(auto &x : v) cin >> x ;

   int sum = accumulate(all(v),0LL) ;

   cout << max(0LL , sum - m) << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }
