#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

vector<vector<int>> g ;
vector<int> vis ;

bool dfs(int node , int par , int color)
{
    vis[node] = color ;

    for(auto child : g[node])
    {
        if(child == par) continue ;
        if(vis[child] == color)
            return true ;
        if(vis[child] == -1 and dfs(child,node,!color))
            return true ;
    }

    return false ;
}

bool bipartite(int n)
{
    vis.assign(n,-1) ;
    for(int i = 1 ; i <= n ; i++)
    {
        if(vis[i] == -1 and dfs(i,-1,true))
            return false ;
    }
    return true ;
}

void solve()
{
    int n;
    cin >> n;
    g = vector<vector<int>>(n+100);
    vis  = vector<int> (n+100, -1);

    bool isBipartite = true ;

    for(int i = 0 ; i < n ;i++)
    {
        int x , y ; cin >> x >> y ;
        g[x].push_back(y);
        g[y].push_back(x);

        if (g[x].size() > 2 or g[y].size() > 2 or x == y)
        {
            isBipartite = false ;
        }

    }

    if(!isBipartite)
    {
        cout << "NO" << nl;
        return ;
    }

    if(bipartite(n))    cout << "YES" << nl ;
    else                cout << "NO" << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



