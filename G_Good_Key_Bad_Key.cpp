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
   int n ; cin >> n ;
   int k ; cin >> k ;
   vector<int> v(n) ; for (auto &x : v) cin >> x ;

   vector<int> prefix(n) ;
   partial_sum(all(v),prefix.begin())  ;

   int best = 0;
   for(int i = 0 ; i < n; i++)
   {
        int sum = prefix[i] ;
        for(int j = 1 ; j < min(n,i+31) ; j++)
        {
            sum += (v[j] >> j) ; 
        }


        sum -= (i + 1) * k; 

        best = max(best,sum) ;
   }

   cout << best << nl ;
   
}
signed main(){   FAST      TestCases      solve() ;  }



