#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int d , n ;
const int N = 2010 ;
// vector < vector < bool >> vis(N, vector < bool >(N));

bool vis[N][N][2] ;

vector < vector < bool >> marked(N, vector < bool >(N));

map<int, int > ans ;
vector < int > g[N] ;

vector < int > cost (N+10 , 0) ;
int aaa = 0 ;

void dfs_node_is_max(int main_node , int node )
{

    if(vis[node][main_node][1]) return  ;
    vis[node][main_node][1]  = true  ; 

    int cn = cost[node] , cm = cost[main_node] ;

    if(cm - cn <= d  and cn <= cm)
    {
        if(marked[node][main_node] or marked[main_node][node]) {return ;} ;
        ans[main_node] =(ans[main_node]%MOD+1%MOD)%MOD ;
        marked[node][main_node] = 1 ;
        aaa++ ;
    }
    else return ;
    for(auto c : g[node])
            dfs_node_is_max(main_node,c) ;
}

void dfs_node_is_min(int main_node ,int node)
{
    int cn = cost[node] , cm = cost[main_node] ;

    if(vis[node][main_node][2]) return  ;
    vis[node][main_node][2]  = true  ; 

    if(cn - cm <= d and cm <= cn )
    {
        if(marked[node][main_node] or marked[main_node][node]) 
        {  
            return ;
        } 
        ans[main_node] =(ans[main_node]%MOD+1%MOD)%MOD ;
        marked[node][main_node] = 1 ;
        aaa++ ;
    }
           
    else   return ;
    
    for(auto c : g[node])
    {
        dfs_node_is_min(main_node,c) ; 
    }
             
}

signed main()
{
    FAST 
    cin >> d >> n ;

    for(int i = 1 ; i <= n ; i++)   cin >> cost[i] ;
    
    for(int i = 1 ; i < n ; i++)
    {
        int x ,  y ;   cin >> x >> y ; 
        g[x].push_back(y) ; g[y].push_back(x) ;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        dfs_node_is_min(i,i) ;
        dfs_node_is_max(i,i) ;
        // dfs_node_is_min(i,i) ;
        memset(vis,0,sizeof(vis)) ;

    }

    for(int i = 1 ; i <= n ; i++)
    {
        // dfs_node_is_min(i,i) ;
        dfs_node_is_max(i,i) ;
        
        // dfs_node_is_min(i,i) ;
    }

    int r = 0 ;
    for(auto [x,y] : ans)
         r = ((y)%MOD + (r)%MOD)%MOD ;

    cout << r ;
    // cerr << aaa << "  " ;

}

