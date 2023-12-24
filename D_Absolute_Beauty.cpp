#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define nl "\n"
// #include"/home/dk/debugging.h"

void solve(int &__case__)
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[i]);
    }

    int res = ans ;

    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int change = -(abs(a[i] - b[i]) + abs(a[j] - b[j])) + (abs(a[i] - b[j]) + abs(a[j] - b[i]));

            res = max(res , ans + change) ;
        }
    }

    cout << res << nl;
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
