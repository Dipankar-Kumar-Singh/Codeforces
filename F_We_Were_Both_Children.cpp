#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define nl "\n"
// #include"/home/dk/Code/debug/debugging.h"

void solve(int &__case__)
{
    int n;
    cin >> n;
    map<int, int> mp;

    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
        if(x <= n )
            mp[x]++ ;
    }


    vector<int> m(n + 1);

    for (auto &[x , fr]  : mp )
    {
        int curr = x;
        while (curr <= n)
        {
            m[curr] += fr;
            curr += x;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = max(m[i], ans);
    }

    cout << ans << nl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCases = 1, case_ = 1;
    cin >> testCases;
    for (int case_ = 1; case_ <= testCases; case_++)
        solve(case_);
}
