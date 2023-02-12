#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
   int n ; cin >> n ;
   map<int,int> m ;
   vector<int> v (n) ; for(auto &x : v) cin >> x , m[x]++;

   int extra = 0 ;
   for(auto &[x,fr] : m) extra += max(fr -1,0LL)  ;

   int ans = set<int>(all(v)).size() ;

   if(extra&1) ans-- ;

   ans = max(ans,0LL) ;

   cout << ans << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }
