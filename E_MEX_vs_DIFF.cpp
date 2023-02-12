#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases       int _test{1};     cin >> _test;     while (_test--)
#define FAST            ios_base::sync_with_stdio(0);     cin.tie(NULL);    cout.tie(NULL);
#define all(x)          (x).begin(), (x).end()
#define nl              "\n"


void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    set<int> s;
    map<int, int> fr;

    for (int i = 0; i <= n; i++)   s.insert(i);

    for (auto &x : v)
    {
        fr[x]++;
        if(s.count(x)) s.erase(x);
    }

    int mex = *s.begin();
    int d = fr.size();

    multiset<int> mm;
    for (auto [x, f] : fr)
    {
        if (x >= v.size())
        {
            for (int i = 0; i < f; i++)
                mm.insert(x);
        }
        else if (f > 1)
        {
            for (int i = 0; i < f - 1; i++)
                mm.insert(x);
        }
    }

    for (int op = 0; op < k; op++)
    {
        if(mm.size()==0) break; 

        s.erase(s.begin());
        mm.erase(mm.begin()) ;

        if(s.size()==0) break;

        mex = *s.begin() ;
    }

    // cerr << "mex = " << mex << nl ;
    // cerr <<  "mx.size() = " <<  mm.size() << nl ;

    int res = ((mm.size()+mex) - mex) ;
    res = max(res,0LL) ;

    cout << res << nl ;
    return ; 

}

signed main()
{
    FAST

        TestCases
        solve();
}
