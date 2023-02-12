#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;

const int N = 1e5  + 10;
vector<bool> vis(N) ;

vector< pair<int,int> > g[N] ;

map< pair<int,int> , int > COLORED ;

int flip_color(int &c)
{
    if(c==2) { c = 3 ;}
    else c = 2 ;
    return c ;
}

void dfs(int node, int color)
{
    if(vis[node]) return ;
    vis[node] = 1 ;
    
    for(auto &[child,col] : g[node])
    {
        if(vis[child]) continue ;
        col = color ;

        COLORED[{node,child}] = color ;
        COLORED[{child,node}] = color ;

        flip_color(color) ;

        dfs(child,color) ;
    }
}



signed main()
{
    FAST 
    t_case
    {
       
        vis.clear() ;
        vis.resize(N) ;
        for(int i = 0 ; i < N ; i++) { g[i].clear() , g[i].clear() ;}
        COLORED.clear() ;

        int n ; cin >> n ; 
        map<int,int> indeg ;
        

        vector<pair<int,int> > vec ;
        vector<int> roots    ;

        set<int> node ;
      

        for(int i = 1 ; i <= n-1 ; i++)
        {
            int x , y ; 
            cin >> x >> y ;
            indeg[x]++ ; indeg[y]++ ;
            g[x].push_back({y,0}) , g[y].push_back({x,0}) ;
            vec.push_back({x,y}) ;
            node.insert(x) , node.insert(y) ;
        }

        int pos = 1 ;

        for(auto &[x,deg] : indeg)
        {
            if(deg>2)
            {
                pos = 0 ;
            }

            if(deg == 2){roots.push_back(x);}
        }

        if(!pos)
        {
            cout << -1 << nl ;
            continue ;
        }

        for(auto &x : roots)
        {   
            dfs(x,2) ;
        }

        for(auto  &nd : node) dfs(nd,2) ;

        for(auto EDGE : vec)
        {
            cout << COLORED[EDGE] << " " ;
        }

        cout << "\n" ;
        
                                  
                                        
                                       
    }
}

