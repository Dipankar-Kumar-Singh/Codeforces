// Am I aggressive enough ?? 
#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

vector<vector<int>> g ;
const int N=8e5+5;
int n, m, tim=0;
int a[N], tin[N], tout[N];

class segmentTree
{
public:
    int N = 1e6 + 10;
    vector<int> seg , lazy , v ;
 
    int mergeOP(int &a, int &b)
    {
        return (a | b) ;
    }
 
    segmentTree(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
        build(0, 0, N - 1);
    }
 
    void update(int l, int r, int value)
    {
        update(0, 0, N - 1, l, r, value);
    }
 
    int query(int l, int r)
    {
        return query(0, 0, N - 1, l, r);
    }
 
    void solvelazy(int n, int s, int e)
    {
        if(lazy[n] == 0 ) return ;
 
        seg[n] = lazy[n] ;
        if (s != e)
        {
            lazy[n * 2 + 1] = lazy[n];
            lazy[n * 2 + 2] = lazy[n];
        }
        lazy[n] = 0;
    }
 
    void build(int n, int s, int e)
    {
        if (s == e)
        {
            seg[n] = v[s];
            return;
        }
        int mid = (s + e) / 2;
        build(n * 2 + 1, s, mid);
        build(n * 2 + 2, mid + 1, e);
        if (s != e)
        {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }
 
    void update(int n, int s, int e, int l, int r, int value)
    {
        solvelazy(n, s, e);
 
        if (s > r or e < l)
        {
            return;
        }
 
        if (s >= l and e <= r)
        {
            lazy[n] = value;
            solvelazy(n, s, e);
            return;
        }
 
        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);
 
        if (s != e)
        {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }
 
    int query(int n, int s, int e, int l, int r)
    {
        solvelazy(n, s, e);
 
        if (s > r or e < l)
        {
            return 0LL;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
 
        int mid = (s + e) / 2;
        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);
        return mergeOP(left, right);
    }
};
 

void solve(int& __case__)
{
    int n; cin >> n ;
    int q; cin >> q ;

    vector<int> colors(n + 1) ; 
    for(int i = 1 ; i  <= n ; i++) cin >> colors[i] , colors[i] = 1LL << colors[i]; 

    g = vector<vector<int>>(n + 1);

    for(int i = 0 ; i + 1 < n ;i++){
        int x,y ; cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    int timer = 0 ; 

     function<void(int,int)> dfs = [&](int node, int par) {
        tin[node] = ++timer ;
        a[timer] = colors[node] ;
        for(int &child : g[node]) { 
            if(child == par) continue ;
            dfs(child,node) ;
        }
        tout[node] = ++timer ;
        a[timer] = colors[node] ;
    };
 
    dfs(1,-1) ;
    vector<int> colorsOnPath ;

    for(int i = 0 ; i <= timer ; i++){
        colorsOnPath.push_back(a[i]) ;
    }

    segmentTree tree(colorsOnPath) ;

    for(int i = 0 ; i < q ; i++){
        int t ; cin >> t ;
        if(t == 1) {
            int v , newColor ; 
            cin >> v >> newColor ;
            newColor = 1LL << newColor ;
            tree.update(tin[v],tout[v],newColor) ;
        }   
        else {
            int v ; cin >> v ;
            int ans = tree.query(tin[v], tout[v]) ;
            cout << __builtin_popcountll(ans) << nl ;
        }
    }
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    // cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}