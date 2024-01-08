/* 
            ~~~~~~~~~~~~{ after 1 Year of Pause, I am back : ) }~~~~~~~~~~ 
    I will fall .... Yep free fall  : ) .... I will go up again ! ... 
    Always proud of my efforts in past - 2nd Year(Start of cp) -- 3rd Year(till 1st sem)
    Last 6 month of college ... want to look back and smile : ) , No Regret 
*/

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

class segmentTreeMIN
{
public:
    int N = 0;
    int MAX_INF_LOCAL_TO_NULLYFY = numeric_limits<int>::max();
    vector<int> seg, v;

    segmentTreeMIN(){};
    segmentTreeMIN(vector<int> vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
        build(0, 0, N - 1);
    }

    int query(int l, int r) { return query(0, 0, N - 1, l, r); }

private:
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
            seg[n] = min(seg[n * 2 + 1], seg[n * 2 + 2]);
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return MAX_INF_LOCAL_TO_NULLYFY;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;

        return min(query(n * 2 + 1, s, mid, l, r), query(n * 2 + 2, mid + 1, e, l, r));
    }
};

class segmentTreeMAX
{
    public:
    int N = 0;
    int INF_LOCAL_TO_NULLYFY = numeric_limits<int>::min() ;
    vector<int> seg , v;

    segmentTreeMAX(){}
    segmentTreeMAX(vector<int> vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
        build(0, 0, N - 1);
    }

    int query(int l, int r) { return query(0, 0, N - 1, l, r); }

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
            seg[n] = max(seg[n * 2 + 1], seg[n * 2 + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return INF_LOCAL_TO_NULLYFY;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;

        if (s != e)
        {
            seg[n] = max(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return max(query(n * 2 + 1, s, mid, l, r), query(n * 2 + 2, mid + 1, e, l, r));
    }
};

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

vector<int> mnTreeV, mxTreeV;

segmentTreeMAX maxTree ;
segmentTreeMIN minTree ;

int dfs(int v, vector<vector<pair<int,int>>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (auto [c , w] : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<pair<int,int>>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (auto [c ,w] : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void dfs_for_segTree(int node ,int par , vector<vector<pair<int,int>>> const &g){
    
    for(auto &[child , w] : g[node]){
        if(child == par) continue;  

        mnTreeV[pos[child]] = w ;
        mxTreeV[pos[child]] = w ;

        dfs_for_segTree(child,node,g) ;

    }
}

void init(vector<vector<pair<int,int>>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n + 1);
    depth = vector<int>(n + 1);
    heavy = vector<int>(n + 1, -1);
    head = vector<int>(n + 1);
    pos = vector<int>(n + 1);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
    dfs_for_segTree(0,-1,adj) ;
}

pair<int,int> query(int a, int b) {
    // int res = 0;
    pair<int, int> res = make_pair(INT_MIN, INT_MAX);
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = maxTree.query(pos[head[b]], pos[b]);
        int cur_heavy_path_min = minTree.query(pos[head[b]], pos[b]);
        // res = max(res, cur_heavy_path_max);
        res.first = max(res.first,cur_heavy_path_max) ;
        res.second = min(res.second,cur_heavy_path_min) ;
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = maxTree.query(pos[a] + 1, pos[b]);
    int last_heavy_path_min = minTree.query(pos[a] + 1, pos[b]);
    res.first = max(res.first,last_heavy_path_max) ;
    res.second = min(res.second,last_heavy_path_min) ;
    return res;
}



void solve(int& __case__)
{
    int n; cin >> n ;
    auto g = vector<vector<pair<int,int>>>(n);

    for(int i = 0 ; i + 1 < n; i++){
        int u , v , w;
        cin >> u >> v >> w;
        u-- ; v-- ;
        g[u].push_back({v,w}) ;
        g[v].push_back({u,w}) ;
    }
    mxTreeV = vector<int>(n,INT_MIN) ;
    mnTreeV = vector<int>(n,INT_MAX) ;

    init(g) ;
    
    maxTree = segmentTreeMAX(mxTreeV) ;
    minTree = segmentTreeMIN(mnTreeV) ;


    int q ;
    cin >> q ; 
    while(q--){
        int u , v ; 
        cin >> u >> v ;
        u-- , v-- ;

        auto [M,m] = query(u,v) ;
        cout << m << " " << M << nl;
    }
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    // cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
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
