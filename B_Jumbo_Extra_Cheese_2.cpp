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
   vector<pair<int,int>> v(n);  

   int ans = 0 ;

   for(auto& [ h , b ] : v) 
   {
        int x , y ; cin >> x >> y  ;
        if( x > y ) swap(x,y) ;

        // x small ... Y BIG 

        b = x ;
        h = y ;

        ans += b ;
   }

   ans *= 2 ;
   sort(all(v)) ;
   ans += v.front().first + v.back().first ;

   for(int i = 0 ; i + 1 < n ; i++)
   {
        auto [ h1 , base1 ] = v[i] ;
        auto [ h2 , base2 ] = v[i + 1 ] ;

        ans += abs(h2 - h1);
   }

   cout << ans << nl;


}
signed main(){   FAST      TestCases      solve() ;  }



