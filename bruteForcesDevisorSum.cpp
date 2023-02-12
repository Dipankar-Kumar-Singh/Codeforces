
// TARUN KA CODE ..

#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define find(s, n) find(be(s), n) - s.begin()
#define fr(i, k, n) for (int i = k; i < n; i++)
#define test  \
    int t;    \
    cin >> t; \
    fr(o, 0, t)
#define vip vector<pair<int, int>>
#define be(v) v.begin(), v.end()
#define sz(s) (int)s.size()
#define mci map<char, int>
#define mii map<int, int>
#define pb emplace_back
#define vi vector<int>
#define nl cout << "\n"
#define mp make_pair
#define int long long
int mod = 5000000;

long long power(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vi v(1e7 + 1);
void func()
{
    for (int i = 1; i < 1e7 + 1; i += 2)
    {
        v[i] = 1;
    }
}

signed main()
{
    fast;
    // func();
    test
    {
        int n, k, flag = 0;
        cin >> n >> k;
        int sum = power(k - 1, 2);
        int rem = n - sum ;
        if ((rem >= k) && (rem&1) && ((n % 2) == (k % 2)))
            cout << "YES";
        else
            cout << "NO";
        nl;
    }
    return 0;
}