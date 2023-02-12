#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

bool Equal(vector<int> &a , vector<int> &b)
{
    for(int i = 0 ; i < a.size() ; i++)
    {
        if(a[i] == b[i])
            return 1 ; 
    }

    return 0 ;
}

void solve()
{
    int n;  cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    if (n == 1)
    {
        cout << -1 << nl;
        return;
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = i + 1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == ans[i])
        {
            if (i + 1 < n)
                swap(ans[i], ans[i + 1]);
            else
                swap(ans[i], ans[i - 1]);
        }
    }

    for (auto x : ans)
        cout << x << " ";
    cout << nl;

}
signed main(){   FAST      TestCases      solve() ;  }
