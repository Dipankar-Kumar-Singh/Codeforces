#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

vector<vector<int>> g ;
vector<int> height ;
vector<int> best  ;

int dfs(int node , int par) 
{
    for(auto child : g[node])
    {
        if(child == par) continue ;
        dfs(child,node);
        height[node] = max( height[child]  , height[node] ) ;
        best[node] += best[child] ;
    }

    height[node]++ ;
    best[node] = max(best[node], height[node]);
    return best[node] ;
}


void solve()
{
    int n; cin >> n;
    g = vector<vector<int>>(n + 1);
    best = height = vector<int> ( n + 1 ) ;
    
    for(int i = 2 ; i <= n  ; i++) 
    {
        int par ; cin >> par ;
        g[par].push_back(i) ;
    }

    cout << dfs(1,0) << nl ;
}
signed main(){   FAST       solve() ;  }

