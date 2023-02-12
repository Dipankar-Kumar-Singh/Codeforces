#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;

int const N = 100000 + 5 ;
vector< vector<int>> g ;
vector<int> reference ;
int test = 0 ;

int pos = 0 ;

vector<vector<int>> allans ;

void dfs(int node , int par , vector<int> v)
{
    v.push_back(node);
    for(auto child : g[node]) 
    {
        if(child == par) continue;
        dfs(child, node, v);
    }

    if(g[node].size() == 1)
    {
        allans.push_back(v);
        return;
    }
}

vector<int> leafNodes ;

void dfs1(int node , int par ,int d)
{
    for(auto child : g[node]) 
    {
        if(child == par) continue ;
        dfs1(child, node, d + 1);
    }

    if(g[node].size() <= 1)
    {
        leafNodes.push_back(node);
    }
}


signed main()
{  
    FAST    
    int n ; cin >> n;
    g = vector<vector<int>>(n+10);

    for(int i = 0 ; i < n - 1 ; i++)
    {
        int x ; cin >> x ;
        int y ; cin >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    int query ;
    cin >> query ;


    dfs1(1, -1, 0);
   
    for(auto node : leafNodes)
        dfs(node, -1, vector<int> ());

    for(auto v : allans)
    {
        for(auto x : v)
        {
            cerr << x << " ";
        }
        cerr << "\n";
    }

    while(query--)
    {
        pos = 0 ;
        int m ; cin >> m; 
        reference = vector<int> (m) ;
        for(auto &x : reference) cin >> x ;
        if(n==1)
        {
            allans.push_back({1}) ;
        }

        for(auto &vv : allans)
        {
            int localcheck = 1 ;
            sort(all(vv)) ;
            for(auto &x : reference)
            {
                if(!binary_search(all(vv),x))
                {
                    localcheck = 0 ;
                    break;
                }
            }

            if(localcheck)
            {
                pos = 1 ;
                break;
            }
        }

        if(pos)
        {
            cout << "YES" << nl ;
        }
        else
        {
            cout << "NO" << nl ;
        }

    }

}