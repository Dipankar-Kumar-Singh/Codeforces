#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
   int n , k ; cin >> n >> k;

   vector<int> v(n) ,p(n+1)  ; for(auto &x : v) cin >> x ;
   partial_sum(all(v),p.begin()+1) ;

   int best = -1 ;
   for(int i = 0 ; i < n; i++)
   {
       int t = n - i ;  //  total number of elements .. 
       int e = min(n-1,i+k-1) ;
       int len = e - i + 1 ;

       int sum = p[e+1] - p[i] ; // sum of already present poitns in range
       int wait = ((k>t) ? (k - t) : 0 );   // waiting time .. 
       int s = ((len-1)*((len-1)+1))/2 ; //  due to automatic apparence of mushroom at every point every second
       int w = wait*len ; // extra points due to waiting [ if waited]
       int ans = sum + s + w ;
       best = max(best,ans) ;
   }
   cout << best << nl;
}
signed main(){   FAST      TestCases      solve() ;  }