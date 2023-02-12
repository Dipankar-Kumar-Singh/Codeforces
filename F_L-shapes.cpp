#include <bits/stdc++.h>
using namespace std;
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int test = 0 ;

int const BAD_SHAPE = -2134 ;
int const ALREADY_VIS = -523 ;
int const FOUND_L = 9999 ;

int n , m ;
vector<vector<int>> vis;
vector<string> v;

vector<int> dx = { 1, 1, 1, -1, -1, -1,  0, 0};
vector<int> dy = {-1, 0, 1, -1,  0,  1, -1, 1};

bool isValid(int i , int j)
{
    if (i < 0 or i >= n)
        return 0;
    if (j < 0 or j >= m)
        return 0;
    return 1;
}

bool check(vector<pair<int,int>>& shape)
{
    if (shape.size() != 3) return 0;

    set<int> x , y ;
    for(auto& [i , j] : shape)
    {
        x.insert(i) , y.insert(j) ;
    }

    return ((x.size() == 2) and (y.size() == 2)) ;
}

int dfs(int i , int j , vector<pair<int,int>> &shape)
{

    if(vis[i][j] == 1 ) return ALREADY_VIS ;
    vis[i][j] = 1 ;
    shape.push_back({i,j}) ;

    for(int d = 0 ; d < 8 ; d++)
    {
        int x = i + dx[d] ;
        int y = j + dy[d] ;
        if(isValid(x,y) and v[x][y] == '*')
        {
            dfs(x,y,shape) ;
        }
    }

    if(check(shape)) return FOUND_L ;
    return BAD_SHAPE ;
}

void solve()
{

    cin >> n >> m ;
    v = vector<string>(n);
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    for(auto& row : v) cin >> row ;

    for(int i = 0 ; i < n ; i++) 
    {
        for(int j = 0 ; j < m ; j++)
        {
            vector<pair<int,int>> shape ;
            if(!vis[i][j] and v[i][j] == '*')
            {
                if(dfs(i, j, shape) == BAD_SHAPE) 
                {
                    cout << "NO" << nl ;
                    return ;
                }
            }
        }
    }

    cout << "YES" << nl ;

}

signed main(){  FAST    TestCases    solve() ; }