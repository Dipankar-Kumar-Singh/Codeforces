#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int const N = 1e5 + 100 ;
int n{} , m{} ;

vector<int> g[N];
vector<bool> vis(N) ;
set<int> color[N] ;

set<int> Q[N] ;

vector<int> vertex_color(N) ;

int ans = 0 ;
int max_car = 0 ;


void dfs(int node)
{

    if(vis[node]) return ;
    vis[node] = 1 ;

    int NC = vertex_color[node] ;

    for(int child : g[node])
    {
        
        int node_color = vertex_color[node] ;
        int child_color = vertex_color[child] ;

        if(node_color != child_color)
        {
            Q[node_color].insert(child_color) ;
        } 
    }

    int cardiality = Q[vertex_color[node]].size() ;


    if( max_car <= cardiality )
    {
        if(max_car == cardiality)
        {
            if(NC < ans)
            {
                max_car = cardiality ;
                ans = vertex_color[node] ;
            }
        
        }
        else
        {
            max_car = cardiality ;
            ans = vertex_color[node] ;
        }
    }


    for(int& child :g[node])
    {
        dfs(child) ;
    }

}

signed main()
{
    FAST 

     cin >> n >> m  ;

     int mini_color = INF ;

     for(int i = 1 ; i <= n ; i++)
     {
        int c ; cin >> c ;
        vertex_color[i] = c ;

        mini_color = min(mini_color , c ) ;
     }

    for(int i = 0 ; i < m ; i++)
    {
        int x , y ; cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(!vis[i]) dfs(i) ;
    }

  
    if(ans == 0)
    {
        ans = mini_color ;
    }

    cout << ans << "\n" ;

}

