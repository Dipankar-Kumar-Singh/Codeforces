#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int divv(int num , int den)
{
    if(den==0) return 0 ; 
    if (num < 0)
    {
        int res = num/den ;
        if (abs(num) % den) res-- ;
        return res ;
    }
    return num/den ;

    // while(num%den) num-- ;
    // return num/den ;
}


void solve()
{
   int n ; cin >> n ;
   int k ; cin >> k ;
   vector<int> v (n) ; for(auto &x : v) cin >> x ;

   sort(begin(v),end(v)) ;
   int mini = *min_element(all(v)) ;
   reverse(begin(v)+1,end(v)) ;

   vector<int> prefix(n+1) ;

   auto a = v ;
   reverse(all(a)) ;
   partial_sum(all(a),prefix.begin()+1) ;

   int best = LONG_LONG_MAX ; 
   for(int t = 0 ; t < n ; t++)
   {
       int sum = prefix[t] + mini*t ;
       if(sum>k)
       {
            int x = divv(k - prefix[t] , t);
            best = min(t+abs(mini-x),best) ;
       }
       else best = min(0LL,best) ;
   }

   cout << best << nl ;




}
signed main(){   FAST      TestCases      solve() ;  }



