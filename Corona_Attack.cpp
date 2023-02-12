#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int const INF = 1e18 + 1000 ;


int maxN = -1 ;
int n ; 
vector<pair<int,int>> peoplelist ; 

int dx[] = {2, 2, -2, -2, -1, -1, 1, 1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

map<pair<int,int>,int> dijkstra()
{
    map<pair<int,int>,int>  dis;
    map<pair<int,int>,int>  vis;
    
    set<tuple<int,int,int>> s ;

    for(auto people : peoplelist) dis[people] = INF ;
    s.insert({1,0,0}) ;
    dis[{0,0}] = 1 ;

    pair source = {0LL,0LL} ;

    while (s.size())
    {
        auto [wt , x , y ] = *s.begin() ;
        s.erase(s.begin()) ;

        pair par = {x,y} ;

        if(vis[par]) continue;
        vis[par] = 1 ;

        int dpar = dis[par] - 1 ;

        for(int i = 0 ; i < 8 ; i++)
        {
            int xx = x + dx[i] ;
            int yy = y + dy[i] ;

            pair child = {xx,yy} ;

            if (xx < 0 or yy < 0)
                continue;
            if (xx > maxN + 10 or yy > maxN + 10)
                continue;

            int dchild = dis[child] - 1 ;
            if(dpar==-1) dis[par] = dpar = INF ;
            if(dchild==-1) dis[child] = dchild = INF ;

            if (dpar + 1 < dchild)
            {
                dis[child] = (dpar + 1) + 1;
                s.insert({dis[child], xx, yy});
            }
        }
    }

    return dis ;
}

signed main()
{   FAST  
    cin >> n ;
    peoplelist.resize(n) ;

    // int maxN = -1 ;
    for(auto &[x,y] : peoplelist)
    {
        cin >> x >> y ;
        maxN = max({maxN, x, y});
    }

    // vector<vector<int>>  dis(maxN+100,vector<int> (maxN+100,LONG_LONG_MAX));
    // vector<vector<int>>  vis(maxN+100,vector<int> (maxN+100,0));

    auto distance = dijkstra() ;

    for(auto &person : peoplelist)
    {
        cout << distance[person]-1 << nl ;
    }

    return 0 ;

    map<pair<int,int>,int>  dis;
    map<pair<int,int>,int>  vis;

    for (int i = 0; i <= maxN + 100; i++)
        for (int j = 0; j <= maxN + 100 ; j++)
            dis[{i, j}] = numeric_limits<int>::max();

    queue<pair<int,int>> q ;
    q.push({0,0}) ;
    dis[{0,0}] = 0 ;

    while (!q.empty())
    {
        auto [x,y] = q.front() ;
        q.pop() ;

        if(vis[{x,y}]) continue;
        vis[{x,y}] = 1 ;

        for(int i = 0 ; i < 8 ; i++)
        {

            int xx = x + dx[i] ;
            int yy = y + dy[i] ;

            if (xx < 0 or yy < 0)
                continue;
            if (xx > maxN + 10 or yy > maxN + 10)
                continue;

            dis[{xx,yy}] = min(dis[{xx,yy}], dis[{x,y}] + 1);
            q.push({xx, yy});
        }
    }

    for(auto &[x,y] : peoplelist)
    {
        cout << dis[{x,y}] << nl ;
    }

}

