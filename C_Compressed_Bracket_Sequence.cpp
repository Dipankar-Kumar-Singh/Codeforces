#include <bits/stdc++.h>
#include"/home/dk/Code/debug/debugging.h"
using namespace std;
using i64 = long long;
#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int c[n];
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    i64 res = 0;
    
    for (int i = 0; i < n; i += 2) {
        i64 mn = c[i];
        i64 cur = c[i];
        for (int j = i + 1; j < n; j++) {
            if (j % 2 == 0) {
                cur += c[j];
            } else {
                i64 l = std::max(0LL, cur - c[j]);
                i64 r = std::min({mn, cur-1 , c[i]-1});
                //dbg(l,r,i,j);
                if (l <= r)
                {
                    res += r - l + 1;
                }
                dbg(i,j,l,r,res);
                cur -= c[j];
                mn = std::min(mn, cur);
            }
        }
    }
    
    std::cout << res << "\n";
    
    return 0;
}
