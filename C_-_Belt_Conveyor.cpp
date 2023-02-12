#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;


void solve()
{

    int n ; cin >> n ;
    int m ; cin >> m ;
    vector<string> v(n) ; for(auto &x : v) cin >> x ;

    vector<vector<int>> vis(n+10,vector<int>(m+10)) ;

    int i = 0, j = 0;

    while (1)
    {
        if (v[i][j] == 'U')
        {
            if (vis[i][j])
            {
                cout << -1 << nl;
                return;
            }
            vis[i][j] = 1;

            if (i == 0)
            {
                cout << ++i << " " << ++j << nl;
                return;
            }
            i-- ;
        }

        else if (v[i][j] == 'D')
        {
            if (vis[i][j])
            {
                cout << -1 << nl;
                return;
            }
            vis[i][j] = 1;

            if (i == n - 1)
            {
                cout << ++i << " " << ++j << nl;
                return;
            }
            i++ ;
        }

        else if (v[i][j] == 'L')
        {
            if (vis[i][j])
            {
                cout << -1 << nl;
                return;
            }
            vis[i][j] = 1;

            if (j == 0)
            {
                cout << ++i << " " << ++j << nl;
                return;
            }
            j-- ;
        }
        else if (v[i][j] == 'R')
        {
            if (vis[i][j])
            {
                cout << -1 << nl;
                return;
            }
            vis[i][j] = 1;

            if (j == m - 1)
            {
                cout << ++i << " " << ++j << nl;
                return;
            }

            j++ ;
        }
    }
}

signed main(){  FAST        solve() ; }