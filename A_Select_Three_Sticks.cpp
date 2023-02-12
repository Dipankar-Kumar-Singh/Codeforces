#include <bits/stdc++.h>
using namespace std;
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e9 ;
int test = 0 ;

long long cost(int a, int b, int c)
{
    int c1 = abs(a - b) + abs(a - c);
    int c2 = abs(b - c) + abs(b - a);
    int c3 = abs(c - a) + abs(c - b);

    return min({c1,c2,c3}) ;
}

void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 

    sort(all(v)) ;

    long long best = 1e18 ;

    for (int i = 0; i  + 2 < n; i++)
    {
        int a = v[i], b = v[i + 1], c = v[i + 2];
        best = min(best, cost(a, b, c));
    }
    cout << best << nl ;
}

signed main(){  FAST    TestCases    solve() ; }