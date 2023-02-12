#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int n, k;    cin >> n >> k;
    auto v = vector<int>(n, 0);
    for (auto &x : v) { char c; cin >> c;    x = (c == 'W');  }

    int paint = 0 ; 
    for(int i = 0 ; i < k ; i++) paint += v[i] ;
    int best = paint ;

    for (int i = 1; i + k - 1 < n; i++)
    {
        paint -= v[i-1] , paint += v[i+k-1] ;
        best = min(best, paint);
    }

    cout << best << "\n" ;
}

signed main(){   FAST      TestCases      solve() ; }
