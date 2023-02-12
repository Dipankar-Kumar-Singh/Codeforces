#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
    string s; cin >> s;
    cout << ( s.size() > 2 ? *min_element(all(s)) : s.back() ) << nl;
}

signed main(){   FAST      TestCases     solve() ;}
