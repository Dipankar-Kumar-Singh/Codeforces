#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

vector<vector<int>> g;
vector<int> color;
vector<int> depth ;
vector<int> subtree ;
int const RED = 1 , BLUE = 2 , GREEN = 0;

void DFS(int node , int parent)
{
    for(auto child : g[node])
    {
        if(child == parent) continue ;
        DFS(child , node) ;
        depth[node] = max(depth[node] , depth[child] + 1) ;
        subtree[node] +=  subtree[child] ;
    }

    if(g[node].size() == 1)
    {
        depth[node]++ ;
    }
    subtree[node]++ ;
}

int decide(int n1 , int n2)
{
    // decide which one to save and which one to mark as red
    if(subtree[n1]!=subtree[n2]) return (subtree[n1] > subtree[n2] ? n1 : n2) ;
    return (depth[n1] < depth[n2] ? n1 : n2) ;
}

void go(int node , int parent)
{
    color[node] = RED ;
    vector<int> children ;

    for(auto child : g[node]) 
    {
        if(child==parent) continue;
        children.push_back(child) ;
    }

    if(children.size()==1)
    {
        int child = children[0] ;
        color[child] = BLUE ;
        return ;
    }

    else if(children.size()==2)
    {
        int c1 = children[0] , c2 = children[1] ;
        int toSave = decide(c1,c2) ;
        int toKill = toSave == c1 ? c2 : c1;
        color[toSave] = BLUE ;
        go(toKill,node) ;
    }
}

int DFS2(int node , int parent)
{
    int green = 0 ;
    for(auto child : g[node])
    {
        if(child == parent) continue ;
        green += DFS2(child , node) ;
    }

    if(color[node] == GREEN) green++ ;
    return green ;
}

void solve()
{

    int n;
    cin >> n;
    g = vector<vector<int>>(n + 10);
    color = depth = subtree = vector<int>(n + 10, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    DFS(1,1);
    go(1,1) ;
    cout << DFS2(1,1) << nl ;
}

signed main(){   FAST      TestCases      solve() ;  }
