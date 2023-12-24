#include <bits/stdc++.h>

#define MODE 0

#if MODE == 0
#define debug(x) cout << #x << ": " << x << endl
#define log(x) cout << x << endl
#define test(x) x
#else
#define debug(x)
#define log(x)
#define test(x)
#endif

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second

using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
#include"/home/dk/debugging.h"

const ll M = 1000000007; // 998244353

void solve() {

    set<int> s = { 2 , 5 , 109 , 235 } ;
    cout << *prev(end(s)) << endl ;
    cout << *--end(s) ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();

    return 0;
}