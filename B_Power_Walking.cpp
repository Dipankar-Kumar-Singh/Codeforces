#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    set<int>s ; int n ; cin >> n ;   
    for (int i = 0, x; i < n; i++) {   cin >> x; s.insert(x);    }
    int sz = s.size() ;
    for(int i = 1 ; i <= n ; i++) cout << max(sz,i) << ' '; cout << "\n" ;
}

signed main(){   FAST      TestCases      solve() ;  }