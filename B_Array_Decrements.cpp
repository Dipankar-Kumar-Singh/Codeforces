#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)        cin >> x;
    for (auto &x : b)        cin >> x;
    int zero = 0;
    int d = 0;

    for (int i = 0; i < n; i++)
    {
        zero += (b[i] == 0);
        if (b[i] == 0)            continue;
        else            d = a[i] - b[i];
        if (b[i] > a[i]){     cout << "NO\n";  return;  }
    }

    if (zero == n)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        a[i] -= d;
        if (a[i] < 0)     a[i] = 0;
    }

    for (int i = 0; i < n; i++)    {
        if (a[i] != b[i])   {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

