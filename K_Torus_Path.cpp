#include <bits/stdc++.h>
using namespace std;
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 
int __case__ = 1 ;





void solve()
{
    int n ; cin >> n ;
    vector<vector<int>> v(n, vector<int>(n));

    long long sum = 0 ;
    int mn = numeric_limits<int>::max() ;

    for(int i = 0 ; i  < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> v[i][j] ;
            sum += v[i][j] ;
        }
        mn = min(mn, v[i][n - i - 1]);
    }
    cout << sum - mn << nl ;
}

signed main() { FAST  solve(); }
