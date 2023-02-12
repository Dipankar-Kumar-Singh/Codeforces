#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n); for (auto &x : v) cin >> x;

    map<int, int> m;
    int ans = 1e18;

    for (int i = 0, j = 0; i < n; i++)
    {
        m[v[i]]++;
        while (m[v[i]] > 1)
        {
            m[v[j]]--;
            j++;
        }

        int x = j;
        int y = n - 1 - i;

        int extra = min(2 * x + y, 2 * y + x);
        ans = min(ans,  extra);
    } ;

    cout << ans << nl ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

