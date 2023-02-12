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
   vector<int> v (n) ; for(auto &x : v) cin >> x ;
   int ans = - 1 ; 

   cerr << bitset<32>(ans) << endl ;

   for(int i = 0; i < n ; i++)
   {
        if(v[i]!=i)
        {
            ans &= v[i] ;
        }

   }

   cout << ans << nl ;






}
signed main(){   FAST      TestCases      solve() ;  }
