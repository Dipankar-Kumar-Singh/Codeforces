#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

const int N = 1e3 + 10 ;
vector<pair<int,int>> g[N][N] ;
bool vis[N][N] ;
int plane[N][N] ;

void dfs(int x,int y )
{
    if(vis[x][y]) return ;
    vis[x][y] = 1 ;
    for(auto &[xx,yy]: g[x][y])  dfs(xx,yy) ;
}

signed main()
{
    FAST 
    t_case
    { int x , y ; cin >> x >> y ;  plane[x][y]  = 1 ; }

    for(int i = 1 ; i < 1001 ; i++)
        for(int j = 1 ; j  < 1001 ; j++)             
            if(plane[i][j] == 1)             
                for(int q = 0 ; q < 1001 ; q++)
                    if(plane[i][q] == 1)
                    {   
                    
                        g[i][q].push_back({i,j}) ;
                        g[i][j].push_back({i,q}) ;
                    }
                

    for(int i = 1 ; i < 1001 ; i++)
        for(int j = 1 ; j  < 1001 ; j++)     
            if(plane[i][j] == 1)
                for(int p = 0 ; p < 1001 ; p++)
                    if(plane[p][j] == 1)
                    { 
                        g[p][j].push_back({i,j}) ;
                        g[i][j].push_back({p,j}) ;
                    }
        
    

    int cc = 0 ;

    for(int i = 1 ; i < 1001 ; i++)
        for(int j = 1 ; j  < 1001 ; j++) 
            if(plane[i][j]==1 and !vis[i][j]) 
                {dfs(i,j) ; cc++ ; }

    cout << cc - 1 ;

}

