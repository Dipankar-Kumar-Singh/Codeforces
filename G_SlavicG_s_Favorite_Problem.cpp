#include <bits/stdc++.h>
using namespace std;
// #include"/home/dk/Code/debug/debugging.h"
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

vector<vector<pair<int,int>>> g ;

int a , b ;
bool possible = 0 ;
set<int> setB ;


void dfsb(int node , int par , int x)
{
    if(par != -1)
        setB.insert(x) ;

    for(auto &[ child , w ] : g[node])
    {
        if( child == par ) continue;
        dfsb(child, node, x ^ w);
    }
}

void dfsa(int node , int par , int x)
{
    if(par != -1)
        if( setB.count(x) ) 
            possible = 1 ;

    for(auto &[ child , w ] : g[node])
    {
        if(child == par) continue;
        if(child == b) continue;

        dfsa(child, node, x ^ w);
    }
}


void solve()
{
    int n ; 
    cin >> n >> a >> b ;
    g = vector<vector<pair<int, int>>>(n + 10);
    setB = set<int>() ;
    possible = 0 ;

    for(int i = 0 ; i + 1 < n ; i++)
    {
        int x ; cin >> x ;
        int y ; cin >> y ;
        int w ; cin >> w  ;

        g[x].push_back({y,w}) ;
        g[y].push_back({x,w}) ;
        
    }

    dfsb(b,-1,0) ;

    dfsa(a,-1,0) ;

     if(setB.contains(0))
    {
        cout << "YES" << nl ;
        return ;
    }
    
    cout << (possible ? "YES" : "NO") << nl;
}

signed main() { FAST TestCases solve(); }
