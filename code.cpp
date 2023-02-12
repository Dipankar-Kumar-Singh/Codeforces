#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n = 1e9;
    vector<bool> prime(1e9, true);
    prime[1] = false;
    prime[0] = false;
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i]==true)
        {
            ans.push_back(i);
        }
        for (int j = 2 * i; j <= n; j+=i)
        {
            prime[j] = false;
        }
    }

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    cout << ans.size() << endl ;
    cout << endl;
}