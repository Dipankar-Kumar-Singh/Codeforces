#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
   int n ; cin >> n ; int q ; cin >> q ;
   vector<int> v (n) ; for(auto &x : v) cin >> x ;

   sort(all(v)) ;
   reverse(all(v)) ;

   vector<int> p(n+1,0) ;

   partial_sum(all(v),p.begin()+1) ;

   while(q--)
   {
        int x , y ; cin >> x >> y ;
        int ans = (p[x] - p[x - y]);
        cout << ans << nl;
   }
}
signed main(){   FAST    solve() ;  }
