#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
    int n ; cin >> n ; int k ; cin >> k ;
    vector<int> v (n) ; for(auto &x : v) cin >> x ;

    for(int i = 0 ; i + 1 < n ; i++)
    {
        if (v[i] < 2 * v[i + 1])
        {
            v[i] = 1;
        }

        else v[i] = 0  ;
    }

    v.back() = 1 ;

    for (auto &x : v)  x = (!x);

    vector<int> p(n+1) ;
    partial_sum(all(v),p.begin()+1);

    int ans = 0 ;
    for(int i = 0 ; i + k < n ;i++)
    {
        if (p[i + k + 1 - 1] - p[i])   continue;
        else ans++;
    }

    cout << ans << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }
