#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define nl "\n"

void solve(int &__case__)
{
    int n; cin >> n;
    int c; cin >> c;
    __int128_t sum_of_square_area = 0;

    vector<int> v(n);
    __int128_t sum = 0;
    for (auto &x : v)
    {
        cin >> x;
        sum_of_square_area += (x * x);
        sum += x;
    }

    function isPossible = [&](__int128_t w, __int128_t target, __int128_t sum) -> bool
    {
        __int128_t margin = 4 * w * ((n * w) + sum);
        return (target - margin - sum_of_square_area >= 0);
    };

    int l = 0, r = 1e18 ;
    while (r - l > 1)
    {
        int mid = midpoint(l, r);
        (isPossible(mid, c, sum) ? l : r) = mid;
    }

    cout << l << nl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    auto x = numeric_limits<__int128_t>::max() ; 
    // cout << x << nl ;

    int digit = 0 ;
    while(x){
        x/=10 ;
        digit++ ;
    }

    cout << "dgiit " << digit << nl ;


    int testCases = 1, case_ = 1; cin >> testCases;
    for (int case_ = 1; case_ <= testCases; case_++) solve(case_);
}