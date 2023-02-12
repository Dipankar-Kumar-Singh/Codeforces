#include <bits/stdc++.h>
using namespace std;
// #define int __int32
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


void solve()
{
   int n ; cin >> n ;
   int k ; cin >> k ;
   vector<int> v(n) ; for (auto &x : v) cin >> x ;
   vector<int> l(n) , r(n) ;

   for(int i = 0 ; i < n; i++)
   {
        l[i] = (v[i]/k) ;
        r[i] = v[i] ;
   }

   int ans = numeric_limits<int>::max() ;

   for(int x = 1 ; x <= 3000 ; x++)
   {
        vector<int> best(n) ;
        for(int i = 0 ; i < n ; i++)
        {
            if( x > r[i] )  best[i] = r[i] ;
            else if( x < l[i] ) best[i] = l[i] ;
            else 
            {
                int q = v[i]/x ;
                while(v[i]/q> x) q++ ;
                best[i] = v[i]/q ;
            }
        }

        sort(begin(best),end(best)) ;
        int localAns = best.back()-best.front() ;
        ans = min(ans,localAns) ;
   }


   cout << ans << "\n";

}
signed main(){   FAST      TestCases      solve() ;  }



