#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   int n , q ; cin >> n >> q ;
   vector<int> v(n) ;
   for(auto &x : v) cin >> x ;
   
   sort(all(v)) ;
   reverse(all(v)) ;

   vector<int> p(n+1) ;
   for(int i = 0 ; i < n ; i++)
   {
       p[i+1] = p[i] + v[i] ; 
   }


   while (q--)
   {
       int target ; cin >> target ;
       auto it = lower_bound(all(p),target) ;
       if(it==p.end()) 
       {
           cout << -1 << nl ;
       }
       else 
       {
           cout << (it-p.begin()) << nl ;
       }
   }
   
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

