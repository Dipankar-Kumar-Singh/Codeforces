#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

bool possible(vector<int> &v , int start , int n )
{
   vector<int> vv(n) ;
   for(int i = 0 ; i < n ; i++)
   {
       vv[i] = start++ ;
   }
   for(int i = 0 ; i < n ; i++) if(abs(v[i]-vv[i])>1) return 0 ;
   return 1 ;
}


void solve()
{
   int n ; cin >>n ;
   vector<int> v(n) ;
   for(auto &x : v) cin >> x ;

   int a = v[0] - 1;
   int b = v[0];
   int c = v[0] + 1;

   if(possible(v,a,n) or possible(v,a,n) or possible(v,c,n))
   {
       cout << "YES\n" ;
   }

   else cout << "NO\n" ;
 
    
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

