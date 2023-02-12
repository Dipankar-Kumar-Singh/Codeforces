#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int N = 2e6 ;
vector<int> dd1(N) ;
vector<int> dd2(N) ;

void solve()
{
   int n  , m ; cin >> n>> m ;
   vector<vector<int>> v(n,vector<int>(m,0)) ;
  
   for(auto &row : v)
        for(auto &x : row) 
            cin >> x  ;

    int maxx = -1 ;

    for(int x = 0 ; x < n ; x++)
    {
        for(int y = 0 ; y < m ; y++)
        {
            dd1[x - y + 1000] = 0;
            dd2[x + y] = 0;
        }
    }

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            dd1[x - y + 1000] += v[x][y];
            dd2[x + y] += v[x][y];
        }
    }

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {

            int res = dd1[x - y + 1000] + dd2[x + y] - v[x][y];
            maxx = max(maxx, res);
        }
    }

    cout << maxx << nl ;
    return ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}




