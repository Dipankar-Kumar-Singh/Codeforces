#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

// BARA HI DIMAAAG KHARAB KAR DENEY WALA QUESTION THA YE ...

int const INF  = 1e18 ;

bool isPossible(int req , vector<vector<int>> &v)
{
    int m =  v.size() ;
    int n =  v[0].size() ;

    vector<int> ok(m) ;
    vector<int> vis(n) ;

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            ok[i] += v[i][j] >= req ;
            vis[j] |= v[i][j] >= req ;
        }
    }

    return *max_element(all(ok)) >= 2 and *min_element(all(vis)) != 0;
}

void solve()
{
    int m , n ; cin >> m >> n ;
    vector<vector<int>> shops(m,vector<int>(n)) ; 
    for(auto &v : shops)  for(auto& x : v) cin >> x ;

    int l = -1 , r = 1e15 ;

    while(r - l > 1)
    {
        int m = midpoint(l,r) ;
        if(isPossible(m,shops)) l = m ;
        else r = m ;
    }

    cout << l << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }

