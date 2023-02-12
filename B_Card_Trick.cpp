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
   vector<int> v(n);  for (auto &x : v) cin >> x;


   int m ; cin >> m ;
   vector<int> rotating(m) ;
   for(auto &x : rotating ) cin >> x ;

   int total = accumulate(begin(rotating),end(rotating),0LL) ;

   total%=n ;

   cout << v[total] << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



