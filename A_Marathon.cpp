#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
    int ans = 0 ;
    vector<int> v (4) ; for(auto &x : v) cin >> x ;
    for(int i = 1 ; i < 4 ; i++) if(v[i]>v[0]) ans++ ;
    cout << ans << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }
