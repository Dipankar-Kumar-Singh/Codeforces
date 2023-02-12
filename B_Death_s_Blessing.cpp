#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;
int INF = numeric_limits<long long>::max() ;

void solve()
{
   int n;   cin >> n;
   vector<int> a(n) , b(n) ;

   for(auto &x : a) cin >> x ;
   for(auto &x : b) cin >> x ;

   int sum = accumulate(all(a), 0LL);
   int bsum = accumulate(all(b),0LL) ;
   int ans = INF ;

   for(auto x : b)
   {
      int cur = sum + bsum - x ;
      ans = min(cur,ans) ;
   }

   cout << ans << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



