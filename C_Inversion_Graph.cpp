#include <bits/stdc++.h>
using namespace std;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 

void observation()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    int m = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        m = max(m, v[i]);

        if (m == (i + 1))
            ans++;
    }

    cout << ans << nl;
}


signed main()
{
    FAST 
    t_case
    {
        observation( ) ;

    }
}

