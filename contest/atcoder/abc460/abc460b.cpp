/*
 *  Title : B - Two Rings
 *  URL   : https://atcoder.jp/contests/abc460/tasks/abc460_b
 */
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define int      long long
#define all(x)   begin(x), end(x)
#define nl       '\n'

#ifdef CPH
    #include "/Users/dk/personal/Codeforces/debugging.h"
    template <class T> void _dbg(T x) { cerr << x << endl; }
    template <class T, class... R> void _dbg(T x, R... r) { cerr << x << " | ", _dbg(r...); }
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", _dbg(__VA_ARGS__)
#else
    #define debug(...)
#endif

    void solve(int &tc)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = (abs(y2 - y1) * abs(y2 - y1)) + (abs(x2 - x1) * abs(x2 - x1));
        int max_r = max(r1,r2) ; 
        int min_r = min(r1,r2) ; 

        bool is_inside = (max_r - min_r) * (max_r - min_r) > d ;

        if ((((r1 + r2) * (r1 + r2)) >= d) && !is_inside) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << "\n";
    } 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases = 1;
    cin >> testCases;             // comment out for single-test problems
    for (int tc = 1; tc <= testCases; tc++)
        solve(tc);

    return 0;
}
