#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n ; cin >> n; 
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    int ans = 0 ;
    int mn = *min_element(all(v)) ;
    for(auto &x : v)
    {
        ans +=  (x-mn) ;
    }

    cout << ans << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

