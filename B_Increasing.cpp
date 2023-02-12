#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;
int test = 0 ;
void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ;

    sort(all(v)) ;

    for(int i = 0 ; i + 1 < n ; i++)
    {
        if (v[i] >= v[i + 1])
        {
            cout << "NO" << nl;
            return ;
        }
    } 

    cout << "YES" << nl ;
    
}

signed main(){  FAST    TestCases    solve() ; }