#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int maxN = -1 ;
int const N = 1e4 + 10 ;
int n , m ;
string order ;
vector<vector<int>> grid ;
vector<vector<int>> vis ;


pair<int,int> finalpos ;

bool underlimit(int x , int y)
{
    if(x<0 or y<0) return 0 ;
    if(x>maxN or y>maxN) return 0 ;
    return 1 ;
}

void dfs(int x , int y , int k)
{
    cerr << nl ;
    if(vis[x][y]) return ;
    vis[x][y] = 1 ;

    finalpos = {x,y} ;

    if(k>=m)
    {
        finalpos = {x,y} ;
        return ;
    }

    cerr  <<  "x = " << x << " y = " << y << nl ;

    char dir = order[k] ;

    cerr << "dir : " <<  dir << " " ;

    if (dir == 'A')
    {
        for (int len = 0; len < 100; len++)
        {
            int xx = x + len, yy = y + len;

            if (!underlimit(xx ,yy))  continue;
            if (grid[xx][yy] and !vis[xx][yy])
            {
                dfs(xx, yy, k + 1);
                return;
            }
        }
    }

    if (dir == 'B')
    {
        for (int len = 0; len < 100; len++)
        {
            int xx = x + len, yy = y - len;

            if (!underlimit(xx ,yy))  continue;
            if (grid[xx][yy]  and !vis[xx][yy])
            {
                dfs(xx, yy, k + 1);
                return;
            }
        }
    }

    if (dir == 'C')
    {
        for (int len = 0; len < 100; len++)
        {
            int xx = x - len, yy = y + len;

            if (!underlimit(xx ,yy))  continue;
            if (grid[xx][yy]  and !vis[xx][yy])
            {
                dfs(xx, yy, k + 1);
                return;
            }

            if(len==99){
                return ;
            }
        }
    }

    if (dir == 'D')
    {
        for (int len = 0; len < 100; len++)
        {
            int xx = x - len, yy = y - len;

            if (!underlimit(xx ,yy))  continue;
            if (grid[xx][yy]  and !vis[xx][yy])
            {
                dfs(xx, yy, k + 1);
                return;
            }
        }
    }

}


signed main()
{   
    FAST  
    cin >> n >> m ;
    cin >> order ;

    vector<pair<int,int>> list(n) ; 

    for(int i = 0 ; i < n ; i++)
    {   
        int x , y ; cin >> x >> y ;
        list[i] = {x,y} ;

        cerr << x << " " << y << nl ;
        maxN = max({maxN,x,y}) ;
    }

    maxN += 100 ;

    cerr << nl ;
    
    grid.resize(maxN + 100 , vector<int> (maxN + 100 ,0)) ;
    vis.resize(maxN + 100 , vector<int> (maxN + 100 ,0)) ;

    for(auto &[x,y] : list)
    {
        grid[x][y] = 1 ;
    }

    auto [xi,yi] = list.front() ;
    dfs(xi,yi,0) ;


    cerr << nl << nl ;

    cout << finalpos.first << " " << finalpos.second;
    cerr << finalpos.first << " " << finalpos.second;
}

