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
   int n;   cin >> n; int k ; cin >> k ;
   vector<int> v(n);  for (auto &x : v) cin >> x;

   int moves = 0 ;

    for(int i = 0 , MIN = v[0] , MAX = v[0] ; i < n ; i++)
    {
        MIN = min(v[i],MIN) ;
        MAX = max(v[i],MAX) ;

        int avg = (MIN + MAX) /2 ;
        if(abs(MIN-avg)<=k and abs(MAX-avg)<=k) continue;
        else 
        {
            MAX = MIN = v[i] ;
            moves++ ;
        }
    }

   cout << moves <<  nl ;
}
signed main(){   FAST      TestCases      solve() ;  }



