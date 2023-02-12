#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
    int n;  cin >> n;
    vector<int> v(n), a;
    for (auto &x : v)    cin >> x;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            a.push_back(lcm(v[i], v[j]));
 
    // for(auto x : a) cerr << x << " " ;

    int ans = a.front();
    for (int x : a)  ans = gcd(ans, x);

    // int ans = v.front();
    // for (int x : v)  ans = gcd(ans, x);

    cout << ans << nl;
}
signed main(){   FAST   solve() ;  }



