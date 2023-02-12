#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

#define ll long long
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a);
        }
        a = (a * a);
        b = b >> 1;
    }
    return (res);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    int  moves = 0 ;

    for (int i = n - 1 ; i > 0 ; i--)
    {
        int &curr = v[i];
        int &pr = v[i - 1];

        if (curr == 0)
        {
            cout << -1 << nl ;
            return ;
        }

        while(pr>=curr)
        {
            pr = pr>>1 ;
            moves++ ;
        }
    }

    cout << moves << nl ;
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

