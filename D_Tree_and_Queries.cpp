#include <bits/stdc++.h>
using namespace std;
#define nl      "\n" 

int const MAXN = 1e5  + 1e3;  
int const BLOCK_SIZE = 400 ;
int cutOff = 0 ;

int timer = 0 ;
vector<vector<int>> g ;
vector<int> color ; 
vector<int> inTime(MAXN * 2) ; 
vector<int> outTime(MAXN * 2) ;
vector<int> flatTree(MAXN * 2) ;


vector<int> nodeFr(MAXN) ; // to check node is visited 2 times in Euler's Path (ND is a part of subtree ? )
vector<int> colorFr(MAXN) ;
vector<int> fr_of_colorFr(MAXN) ; 

void dfs_Euler(int node, int par) {

    inTime[node] = ++timer ; 
    flatTree[timer] = node ;

    for(auto child : g[node]) { 
        if(child == par) continue;
        dfs_Euler(child,node) ;
    }
    
    outTime[node] = ++timer ;
    flatTree[timer] = node ;
}

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    int query(int l, int r) {
        return sum(r) - sum(l-1) ;
    }
};

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , q ; cin >> n >> q ; 
    g = vector<vector<int>>(n + 1) ; 
    color = vector<int>(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> color[i] ; 

    FenwickTree tree(MAXN) ;
    
    for(int i = 0 ; i + 1 < n ;i++ ) {
        int x , y ; 
        cin >> x >> y ; 
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }   

    dfs_Euler(1,-1) ;

    vector<array<int,4>> quries(q) ;
    for(int i = 0 ; i < q ; i++ ) {
        auto &[l, r, k, id] = quries[i];
        int node ; cin >> node ;  
        cin >> k ;
        l = inTime[node]  ;
        r = outTime[node] ;
        id = i ;
    };

    std::sort(begin(quries),end(quries),[&](array<int,4> &a , array<int,4> &b)->bool{
        int block1 = a[0] / BLOCK_SIZE;
        int block2 = b[0] / BLOCK_SIZE ;

        if(block1 == block2) { 
            if( block1 & 1 ) 
                return a[1] < b[1] ;
            else 
                return b[1] < a[1] ;
        }
        return block1 < block2 ;
    }) ;

    function add = [&](int id)->void{ 
        // id -- Time 
        if(id == -1 ) return;
        int node = flatTree[id] ;
        nodeFr[node]++ ;
        if(nodeFr[node] == 2) {
            int old_fr = colorFr[color[node]] ;
            colorFr[color[node]]++ ;
            int new_fr = colorFr[color[node]] ;

            fr_of_colorFr[old_fr]-- ;
            tree.add(old_fr, -1) ;

            fr_of_colorFr[new_fr]++ ;
            tree.add(new_fr, 1) ;
        }
    };

    function sub = [&](int id)->void{ 
        if(id == -1 ) return ;
        int node = flatTree[id] ;
        nodeFr[node]-- ;
        if(nodeFr[node] == 1) {
            // eariler ... it was contributing ... 
            // now .. remove it's old contribution as it is inactive 
            int old_fr = colorFr[color[node]] ;
            colorFr[color[node]]-- ;
            int new_fr = colorFr[color[node]] ;

            fr_of_colorFr[old_fr]-- ;
            tree.add(old_fr, -1) ;

            fr_of_colorFr[new_fr]++ ;
            tree.add(new_fr, 1) ;
        }
    };

    vector<int> ans(q) ;
   
    int ml = 0 , mr = -1 ;
    for(auto &[ l , r , k , id ] : quries ) {
        cutOff = k ;
        while( ml < l ) sub(ml++) ;
        while( ml > l ) add(--ml) ;
        while( mr > r ) sub(mr--);
        while( mr < r ) add(++mr) ;

        ans[id] = tree.query(k,MAXN - 1) ;
    }

    for(auto &x : ans ) 
        cout << x << nl ;
}
