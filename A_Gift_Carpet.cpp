#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define nl "\n"

void solve(int &__case__)
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<string> v(n);

    for (auto &x : v)
        cin >> x;

    string target = "vika";
    reverse(all(target));

    for (int j = 0; j < m; j++)
    {
        if (target.empty())
        {
            cout << "YES" << nl;
            return;
        }

        char t = target.back();
        bool found = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] == t)
            {
                found = 1;
                break;
            }
        }
        if (found && target.size())
            target.pop_back();
    }

    if (target.empty())
    {
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
    }
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
