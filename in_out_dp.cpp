#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

int const N = 1e6  ;
vector<int> in , out ;
vector<vector<int>> g ;

int dfs(int node , int par)
{
    for(auto child : g[node])
    {
        if(child == par)  continue;
        dfs(child , node) ;
        in[node] = max( in[node] , 1 + in[child]) ;
    }

    return in[node] ;
}

int dfs2(int node , int par)
{
    int mx1 = 0  , mx2 = 0 ;  // mx1 >= mx2 ;


    // VVIP ---> Use a differnt loop for the calculation of two maximum element .
    for(auto child : g[node])
    {
        if(child == par) continue ;

        if(in[child] > mx1) 
        {
            mx2 = mx1 ;
            mx1 = in[child] ;
        }

        else if(in[child] > mx2)
        {
            mx2 = in[child] ;
        }

    }


    for(auto child : g[node])
    {
        if(child == par) continue ;
        int use = mx1 ;

        // we dealint with children and parent is not the hero ...
        // we are currently at a child which is a random child and then we are finding it's another sibling .. 
        // either out of parent will give the max len ..
        // or .. from this child ==> go to the parent ==> then ==> go to another child ..
        // x --> p --> y  ==> [x , y ] are sibling ... p ==> their parent ...

        // noramaly x is any random node .. and y is the longest yeilding child of p 
        // so x --> p --> y 
        // what if .. x is out current y --> then ... x === y --> to deal with this case
        // we will make y --> as second best child --> best + second best --> can be one of the possible ans ..

        // but in case of dimainer ... we are very much sure .. that .. best + second best will only contribute in this for loop
        // but we are trying to build outDP vector also .. thus looping agian ..
        
        if( in[child] == use )
        {
            use = mx2 ;
            // second best .. because x is the best .. so 
        }
        out[child] = max( out[node] , 1 + use ) ;
        out[child]++ ; // because we have to go tol parent anyhow --> +1 to reach to parent ..

        dfs2(child , node) ;
    }

    return out[node] ;
}

void solve()
{
    int n ; cin >> n ;
    g = vector<vector<int>>(n + 10);
    in = out = vector<int>(n + 10);

    for(int i = 1 ; i < n ; i++)
    {
        int x , y ; 
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    dfs(1,-1) ;
    dfs2(1,-1) ;

    vector<int> dimeter_when_root(n+1) ;

    for(int node = 1 ; node <= n ; node++)
    {
        dimeter_when_root[node] = max(out[node], in[node]);
        cout << dimeter_when_root[node] << ' ' ; 
    }

    cout << nl ;
}

signed main() { FAST  solve(); }

/*
    Input :
    10
    1 2
    1 3 
    1 4
    2 5
    2 6 
    3 7 
    4 8 
    7 9 
    7 10

    output : 3 4 3 4 5 5 4 5 5 5
*/