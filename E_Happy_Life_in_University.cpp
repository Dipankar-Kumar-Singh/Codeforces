/* 
            ~~~~~~~~~~~~{ after 1 Year of Pause, I am back : ) }~~~~~~~~~~ 
    I will fall .... Yep free fall  : ) .... I will go up again ! ... 
    Always proud of my efforts in past - 2nd Year(Start of cp) -- 3rd Year(till 1st sem)
    Last 6 month of college ... want to look back and smile : ) , No Regret 
*/

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define nl      "\n" 

class SegmentTree{

    int N ;
    vector<int> seg , lazy ;
    public :
    SegmentTree(int n) : N(n) {
        N = n ;
        seg = lazy = vector<int>( 4 * N + 10) ;
    }

private:
    void pushLazy(int node, int s, int e)
    {
        if (lazy[node] == 0) return;

        seg[node] += lazy[node];

        if (s != e){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2]  += lazy[node];
        }

        lazy[node] = 0;
    }

    void update(int node , int s , int e , int l, int r, int val){
        pushLazy(node , s , e ) ;

        if( s > r or e < l ) return ;
        if( l <= s and e <= r) {
            lazy[node] += val ;
            pushLazy(node , s , e ) ;
            return ;
        }

        int mid = ( s + e ) / 2 ;
        update(node * 2 + 1, s, mid, l, r, val);
        update(node * 2 + 2, mid + 1, e, l, r, val);
        seg[node] = max( seg[node*2 + 1] , seg[node*2 + 2]);
    }

    int query(int node, int s, int e, int l, int r) {
        pushLazy(node, s, e);

        if( s > r or e < l ) return 0; 
        if( l <= s and e <= r ) {
            return seg[node];
        }   

        int mid = ( s + e ) / 2 ;

        return max(
            query(node * 2 + 1, s, mid, l, r),
            query(node * 2 + 2, mid + 1, e, l, r));
    }

public:
    void update(int l, int r, int val) { update(0, 0, N - 1, l, r, val); }
    int query(int l, int r) { return query(0, 0, N - 1, l, r); }
};


void solve(int& __case__)
{
    int n; cin >> n;
    vector<vector<int>> g(n + 1) ;
    vector<int> parent(n + 1) ; parent[1] = -1 ;
    for(int node = 2 ; node <= n ; node++){
        int par ; cin >> par ; 
        g[par].push_back(node) ;
    }    

    vector<int> color ( n + 1 ) ; 
    for(int node = 1 ; node <= n ; node++){
        cin >> color[node] ;
    }

    vector<int> tin , tout , path ; 
    tin = tout = vector<int>(n+1) ;
    path = vector<int>(n+1);

    int timer = 0 ;
    function<void(int)> dfs_euler = [&](int node) -> void {
        tin[node] = timer++ ;
        path[tin[node]] = node ;
        for(int child : g[node]) {
            dfs_euler(child) ;
        }
        tout[node] = timer - 1;
    };

    dfs_euler(1) ;

    vector<set<int>> colorSeen(n + 1) ; 

    SegmentTree tree(n+1) ;
    long long ans = 1 ;

    function<void(int)> dfs = [&](int node) -> void {

        for(int child : g[node]) {
            dfs(child) ;
        }

        auto it = colorSeen[color[node]].lower_bound(tin[node]) ;
        while(it != colorSeen[color[node]].end()){
            if(*it > tout[node]) {
                break;
            } 
            // node with the same color 
            // and comes before exiting current node is a part of subTree of current Node
            int y = path[*it] ;
            it = colorSeen[color[node]].erase(it) ; // after delete , it gives next itrator in the seq automatically .. 
            int l = tin[y] , r = tout[y] ;
            tree.update(l,r,-1) ;
        }

        colorSeen[color[node]].insert(tin[node]) ;
        tree.update(tin[node],tout[node],1) ;
        
        long long res = 1 ;
        for(int y : g[node]) {
            int d = tree.query(tin[y],tout[y]) ;
            ans = std::max(ans , d * res) ;
            res = max(res , d ) ;
        }
        
    };

    dfs(1) ;
    cout << ans << nl ;
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

/*
            ██████╗ ██╗██████╗  █████╗ ███╗   ██╗██╗  ██╗ █████╗ ██████╗ 
            ██╔══██╗██║██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝██╔══██╗██╔══██╗
            ██║  ██║██║██████╔╝███████║██╔██╗ ██║█████╔╝ ███████║██████╔╝
            ██║  ██║██║██╔═══╝ ██╔══██║██║╚██╗██║██╔═██╗ ██╔══██║██╔══██╗
            ██████╔╝██║██║     ██║  ██║██║ ╚████║██║  ██╗██║  ██║██║  ██║
            ╚═════╝ ╚═╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
*/                                                          
