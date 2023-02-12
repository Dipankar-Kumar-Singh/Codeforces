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
   vector<int> v(n) ;   for(auto &x : v) cin >> x ;

   multiset<int> m(all(v));
   int ans = LONG_LONG_MAX;

   for (int i = 0; i + 1 < n; i++)
   {
       int x = v[i];
       int y = v[i + 1];

       int half_a = ceil(x / 2.0);
       int half_b = ceil(y / 2.0);
       int half_sum = ((x + 1 + y + 1) / 3);

       int res = max({half_a, half_b, half_sum});
       ans = min(ans, res);
   }

   if (n > 2)
       for (int i = 1; i + 1 < n; i++)
       {
           int l = v[i - 1], c = v[i], r = v[i + 1];
           ans = min(ans, (int)ceil((l + r) / 2.0));
       }

   sort(all(v));
   int a = v[0], b = v[1];
   int res = ceil(a / 2.0) + ceil(b / 2.0);
   ans = min(res, ans);
   cout << ans << nl;
}

signed main()
{   FAST  
    solve() ;  
}

