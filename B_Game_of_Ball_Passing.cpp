#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

void solve()
{
    int n ; cin >>n ;
    vector<int> v(n) ; 
    for(auto &x : v) cin >> x ;

    sort(all(v)) ; reverse(all(v)) ;

    int ans = (accumulate(all(v), 0) ? 1 : 0);

    multiset<int> s (all(v)) ;

    while (v.size())
    {
       
    }
    
  
    cout << ans << nl ;


    

}

signed main()
{   FAST  

    TestCases  
    solve() ;  



}

