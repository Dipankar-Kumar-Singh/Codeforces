#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
   int n;   cin >> n;
   vector<int> fr (1e5+1000) ;
   vector<int> v(n);  for (auto &x : v) cin >> x , fr[x]++;
   sort(all(v));

   vector<int> dp(1e5+10,0) ;

   dp[1] = fr[1] ; 

   for(int num = 2 ; num <= v.back() ; num++)
   {
        dp[num] = max(fr[num]*num + dp[num-2] , dp[num-1]) ;
   }

   cout << *max_element(all(dp)) ;
}
signed main(){   FAST            solve() ;  }



