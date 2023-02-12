#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int par[2001] ;
vector<int> g[2001] ;
vector<bool> vis(2001,0) ;

int max_h = 1 ;

void dfs(int v , int d){

    if(vis[v]) return ;

    max_h = max(max_h , d) ;
    vis[v] = 1 ;

    // cerr << "visiting : " << v << "   H = " << d << "\n" ;

    for(auto & node : g[v]){
        dfs(node,d+1) ;
    }
}

signed main()
{
    FAST 
    int n ; cin >> n ; 
    
    for(int i = 1 ; i <= n ; i++){

        int p ; cin >> p ; 
        int u = i , v = p ;

        if(p == -1 ) { par[i] = i ; continue ; }
        g[u].push_back(v) ; g[v].push_back(u) ;

        par[i] = p ;
    }

    for(int i = 1 ; i <= n ; i++){
       if(par[i]==i) dfs(i,1) ;
    }

    cout << max_h  ;
}

