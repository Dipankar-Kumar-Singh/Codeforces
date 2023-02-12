#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

long long ceil(long long a, long long b) {    if (a == 0) return 0;    return (a - 1)/b + 1;}

void solve()
{
   int n ; cin >> n ;
   vector<int> v (n) ; for(auto &x : v) cin >> x ;

   vector<int> ans(n) ; 

   set<int> s ; 
   for(int i = 1 ; i <= n ; i++) s.insert(i) ;


   for(int i = n-1 ; i >= 0 ; i--)
   {
        int index = i + 1 ;
        if(v[i])
        {
            int b = v[i] ;

            int low = ceil(index,b+1) ;
            while(index/low>b) low++ ;
 
            auto it = s.lower_bound(low) ;
        
            ans[i] = (*it) ;
            s.erase(it) ;   
              
        }
   }


   for(int i = n-1 ; i >= 0 ; i--)
   {
        int index = i + 1 ;
        if(v[i]==0)
        {
            int b = v[i] ;

            int low = ceil(index,b+1) ;
            while(index/low>b) low++ ;

            auto it = s.lower_bound(low) ;
            ans[i] = (*it) ;
            s.erase(it) ;   
        }
   }

   for(auto x : ans) cout << x << " " ;
   cout << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }
