#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int n , m ;
vector<vector<int>> v ;
vector<tuple<int,int,int>> ans ;
int magic = 0 ;

bool okay(int x , int y )
{
    if(x<0 or y < 0) return 0 ;
    if(x>=n-1) return 0 ;
    if(y>=m-1) return 0 ;
    return 1 ;
}

void fill_zeros(int x , int y)
{
     for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                v[x + i][y + j] = 0 ;
}

vector<int> colors_at_cell(int x ,int y )
{
    set<int> s ;
    vector<int> dummy {9,9,9,9,9,9,9,9} ;
    if(!okay(x,y)) return dummy ;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
                s.insert(v[x + i][y + j]);

    vector<int> col (all(s)) ;
    return col ; 
}

bool all_equal(int x , int y)
{
  return ((colors_at_cell(x,y)).size()==1) ;
}


signed main()
{
    FAST 
    cin >> n >> m ;
    v.resize(n,vector<int>(m)) ;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> v[i][j] ;

    queue<pair<int,int>> q ;

    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j + 1 < m; j++)
            if (all_equal(i, j))
                q.push({i, j});

    while (q.size())
    {

       auto [x,y] = q.front()  ; q.pop() ;
       auto col = colors_at_cell(x,y) ;

       int c = col.back();
       if(c==0) continue ;

       ans.push_back({x, y, c});

       fill_zeros(x, y);

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1 ; j < 2; j++)
            {
                int X = x + i, Y = y + j;

                if(!okay(X,Y)) continue ;

                auto C = colors_at_cell(X,Y);

                if (C.size() == 2)
                {
                     q.push({X, Y});
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j]) {  cout << -1;  exit(0); }

    reverse(all(ans)) ;

    cout << ans.size() << nl ;

    for (auto &[x, y, c] : ans)
    {
        cout << x +1 << " " << y+1  << " " << c << "\n";
    }
}

