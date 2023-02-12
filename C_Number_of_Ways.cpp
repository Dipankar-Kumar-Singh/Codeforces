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
   vector<int> v (n) ; for(auto &x : v) cin >> x ;

   int c = accumulate(all(v),0LL) ;

//    multiset<int> a ;
   map<int,int> a ;

   int b = 0 ;

   int ans = 0 ;


   for(int i = 0 ; i < n ; i++)
   {
        b += v[i] ;
        c -= v[i] ;


        if(i==0 or i==n-1) {a[b]++ ; continue;}

        int x = b - c ;
        if(a[x])
        {
            int y = b - x ;
            if(x==y)
            {
                cerr << i << " \n" ;
                ans += a[x] ;
            }
        }

        a[b]++  ;
   }

   cout << ans << nl ;


}
signed main(){   FAST      solve() ;  }



