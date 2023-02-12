#include <bits/stdc++.h>
using namespace std;

    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
    // Keep Going, Never Give up .

#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

const int N = sqrt(1e9) ;
vector<int> lp(N + 1);
vector<int> prime;

void calculate()
{
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0){
            lp[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < (int)prime.size() && prime[j] <= lp[i] && i * prime[j] <= N; ++j)
            lp[i * prime[j]] = prime[j];
    }
}

void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(auto &x : v )    cin >> x;

    for (auto p : prime)
    {
        int count = 0;

        for (auto &x : v)
        {
            if (x % p == 0)
                count++;

            while (x % p == 0)
                x /= p;
        }

        if (count > 1)
        {
            cout << "YES" << nl;
            return;
        }
    }

    multiset<int> s;
    for (auto x : v)
    {
        if (x != 1 and s.find(x) != s.end())
        {
            cout << "YES" << nl;
            return;
        }

        s.insert(x);
    }

    cout << "NO\n";
    return;
}

signed main()
{ 
    FAST calculate();
    TestCases solve();
}