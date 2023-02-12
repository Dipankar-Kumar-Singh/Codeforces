#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int const N = 1e6 ;
vector<vector<int>> paths  ;
vector<int> g[N] ;


void dfs(int node, vector<int> &v)
{
    v.push_back(node) ;
    int ct = 0 ;

    if(g[node].size()==0)
    {
        paths.push_back(v) ;
        return ;
    }

    for(auto child : g[node])
    {
        if(ct==0)
        {
            dfs(child,v) ;
        }
        else 
        {
            vector<int> nv ;
            dfs(child,nv) ;
        }
        ct++ ;
    }
}

void solve()
{
    int n ; cin >> n; 
    paths.clear() ;

    for(int i = 0 ; i <= n + 100 ; i++)
    {
        g[i].clear() ;
    }

    vector<int> parent(n+1) ;
    int root = 0 ;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> parent[i] ;
        if(parent[i]==i) root = i ;
        if(i!=root)
            g[parent[i]].push_back(i);
    }

    vector<int> vv ;
    dfs(root,vv) ;

    cout << paths.size() << nl ;
    for(auto path : paths)
    {
        cout << path.size() << nl ;
        for(auto node : path)
        {
            cout << node << " " ;
        }
        cout << nl ;
    }

    cout << nl ;




}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

