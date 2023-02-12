#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

char const wall = '#' ;
char const good = 'G' ;
char const bad = 'B' ; 
char const clean = '.' ;
int n , m ;

vector<vector<char>> v ;

int dx[4] = {1, -1,  0,  0};
int dy[4] = {0,  0 , 1, -1} ;

bool underlimit(int i, int j)
{
    if (i < 0 or j < 0)        return 0;
    if (i >= n or j >= m)        return 0;
    return 1;
}

vector<vector<int>> vis(55,vector<int> (55,0)) ;

void dfs2(int i , int j)
{
    if(v[i][j] == wall) return ;
    vis[i][j] = 1 ; 

    for(int k = 0 ; k < 4 ; k++)
    {
        int x = i + dx[k] ,  y = j + dy[k] ;

        if (!underlimit(x,y)) continue;
        if(vis[x][y]) continue; 
        if(vis[x][y]==wall) continue;

        dfs2(x,y) ;
    }
}

void clear_vis()
{
    for(int i = 0 ; i < n  ; i++)
        for(int j = 0 ; j < m ; j++) vis[i][j] = 0; 
}

void solve()
{

    cin >> n >> m ;
    v.clear() ;
    v.resize(n,vector<char>(m,0)) ;

    clear_vis() ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> v[i][j] ;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(v[i][j]==bad)
            {
                for(int k = 0 ; k < 4 ; k++)
                {
                    int x = i + dx[k] ;
                    int y = j + dy[k] ;

                    if(!underlimit(x,y)) continue;

                    if(v[x][y] == clean) 
                    {
                        v[x][y] = wall ;
                    }
                } 
            } 
        }
    }

    dfs2(n-1,m-1) ;

    for(int i = 0 ; i < n ;i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            bool c1 = (v[i][j] == bad ) and  vis[i][j] ;
            bool c2 = (v[i][j] == good) and !vis[i][j] ;

            if(c1 or c2)
            {
                cout << "No\n" ; return ;
            } 
        }
    }

    cout << "Yes\n" ; return ;
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

