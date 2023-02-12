#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;


const int N = 1e5  + 100; 

vector< pair< int, int > >  g[N] ;
vector  < bool >  vis (N) ;

vector<int> pass(N) ;

void dfs(int node)
{
    if(vis[node]) return ;
    vis[node] =  1 ; 

    for(auto &child : g[node])
    {
        
        int &c = child.first ;
        int &t = child.second ;

        if(vis[c]) continue ; 

        if(t == 2)
        {
            pass[node] = 1 ;
            pass[c] = 1  ;
        }

        dfs(c) ;
        pass[node] += pass[c] ;

    }
}


signed main()
{
    FAST 
    int n {}; cin >> n ; 

    for( int i = 1 ; i <  n ; i++)
    {
        int x , y ;  int t ;
        cin >> x >> y  ;
        cin  >> t ;
        g[x].push_back({y,t}) , g[y].push_back({x,t}) ; 
       
    }

    dfs(1) ;
    vector<int> ans  ;

    for(int i = 1 ; i <= n ; i++)
    {
        pass[i] == 1  ?  ans.push_back(i) : void() ;
    }

    cout << ans.size() << nl; 
    for(auto f : ans) cout << f << " " ;

}
