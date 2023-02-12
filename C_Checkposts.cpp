#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------- */
/*    USED KOSA RAJU ALORITHM --> TO FIND STRONGLY CONNECTED COMPONENTS ..    */
/* -------------------------------------------------------------------------- */


#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

const int N = 1e5 + 10 ; 
vector<int>  g[N] ;
vector<int>  g2[N] ;
bool vis2[N] ;
bool vis[N] ;

stack<int> st ;

void dfs(int node ){
    if(vis[node]) return ;
    vis[node] = 1 ;

    for(auto &child : g[node])
    {
        dfs(child) ;
    }

    st.push(node) ;
}

void dfs2(int node , vector<int> &v){
    
    if(vis[node]) return ;
    vis[node] = 1 ;
    v.push_back(node) ; 

    for(auto &child : g2[node])
    {
        dfs2(child,v) ;
    }

    
}

signed main()
{
    FAST 

    int n ; cin >> n ;
    
    vector<int> cost(n+1) ;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >>  cost[i] ;
    }

    int m ; cin >> m ;


    while(m--) 
    {   
        int x ,  y ; 
        cin >> x >> y ;
        g[x].push_back(y) ;      
    }


    // stack<int> st ;

    for(int i = 1 ; i <= n  ;  i++){
        if(!vis[i])
            dfs(i) ;
    }

    

    /* -------------------------------------------------------------------------- */
    // transposing ...

    for(int i = 1 ; i <=n ; i++){
        if(g[i].empty()) g2[i].push_back(i) ; 
        for(int child : g[i]){
            g2[child].push_back(i) ;
        }
    }
    /* -------------------------------------------------------------------------- */

    vector<vector<int>> v_main ;
    memset(vis,0,size(vis)) ;

    while (!st.empty())
    {
        int cur  = st.top( ) ; st.pop() ;
        vector<int> v ;
      

        if(vis[cur]){ continue ;}
        if(!vis[cur]) { dfs2(cur,v)  ;}
        v_main.push_back(v) ;
    }


    for(auto v : v_main){ for(auto x : v) {cerr << x << " " ;} cerr << "\n" ;}
    
    int total_cost = 0 , total_ways = 1 ;
    vector<int> ways ;

    for(auto &v : v_main){
        int fr = 0;
        int min_cost = INF;
        for(auto &e : v ) { min_cost = min( min_cost , cost[e]) ; }
        for(auto &e : v){ if(cost[e] == min_cost ) fr++ ;  }
        ways.push_back(fr) ;
        total_cost  +=  min_cost ;
    }

    for(int i = 0 ; i <  ways.size() ; i++)
    {
        total_ways = (total_ways *  ways[i])%MOD ;
    }

    cout << total_cost << " " << total_ways ;

}

