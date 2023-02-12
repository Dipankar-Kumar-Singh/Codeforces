#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int N = 3e5 ;
vector< vector<int> > g(N);
vector<int> depth(N,0) ;
vector<bool> isIndustry(N) ;
vector<int> sizeOFSubTree(N) ;
int ans = 0 ;

void DFS(int node , int parent)
{
    for(auto child : g[node])
    {
        if(child == parent) continue ;
        depth[child] = depth[node] + 1 ;
        DFS( child , node ) ;
        sizeOFSubTree[node] += sizeOFSubTree[child] ;
    }
    sizeOFSubTree[node]++ ;
}

void DFS2(int node , int parent , int tourist)
{
    if(isIndustry[node] == 0) tourist++ ;

    for(auto child : g[node])
    {
        if(child == parent) continue ;
        DFS2( child , node ,tourist) ;
    }

    if(isIndustry[node]==1)
    {
        ans += tourist ;
    }
}

signed main(){   
    FAST 

    int n , k ; cin >> n >> k ; 

    for(int i = 1 ; i < n; i++)
    {
        int x , y ; cin >> x >> y ;
        g[x].push_back(y)  ;
        g[y].push_back(x) ;
    }

    DFS(1,1) ;
    depth[1] = 0 ;

    vector<int> array ;

    for(int node = 1; node <= n ; node++)  array.push_back(node) ;

    sort
    (   
        all(array),
        [  ]
        (int n1 , int n2)
        {
            return depth[n1] - sizeOFSubTree[n1] > depth[n2] - sizeOFSubTree[n2] ; 
        }
    );

    for(int i = 0 ; i < k ; i++) 
    {
        isIndustry[array[i]] = 1 ;
    }

    DFS2(1,1,0) ;
    cout << ans << nl ;
}
