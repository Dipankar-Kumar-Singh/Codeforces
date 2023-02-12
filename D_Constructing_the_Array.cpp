#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

long long lengthOfSegment(int l , int r)
{
    return r - l + 1 ;
}

void solve()
{
   int n ; cin >> n ;
   
   set<tuple<int,int,int>> s ;
   s.insert({-n,0,n-1}) ;

   vector<int> v(n) ;
   int current = 0 ;

   while(!s.empty())
   {
        auto [sz, l , r] = *s.begin() ;
        s.erase(s.begin()) ;

        // sz = -sz  ;
            
        int mid = midpoint(l,r) ;
        if(v[mid]) continue ;
        v[mid] = ++current ;

        tuple<int,int,int>  a = {-lengthOfSegment(l,mid-1),l,mid-1} ;
        tuple<int,int,int>  b = {-lengthOfSegment(mid+1,r),mid+1,r} ;

        if(mid- 1 >= l)     s.insert(a) ;
        if(mid +1 <= r)     s.insert(b) ;

   }

   for(auto x : v) cout << x << " " ;
   cout << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }
