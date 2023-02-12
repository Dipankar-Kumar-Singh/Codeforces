#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   
   int n ; cin >> n ;
   vector<int> v(n) ;
   map<int,int> fr ; 
   for(auto &x : v) cin >> x , fr[x]++ ;

    int mx_fr = 0 ;
    for(auto [_e,f] :fr)  mx_fr = max(mx_fr , f) ;

    int a = mx_fr , b = n - mx_fr ;

    int ans = 0  ;

    while (a!=n)
    {
        int delta = min(a,b) ;
        a += delta ; b -= delta ;
        ans += (delta + 1) ;
    }

    cout << ans << nl ;
    


 


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

