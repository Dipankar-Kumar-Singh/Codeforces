#include"bits/stdc++.h"
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

vector<vector<int>> g ;

class SparseTableRMinQ  // Reange Minimum for LCA & return { min_element , id } , is is required to find who is the boss of this ID -> It belong to which node 
{   
    int LOG{}, MAXN = 1E5;
    vector<vector<pair<int,int>>> st ;  // ( min_element , index )

    public:
    SparseTableRMinQ(){} ;
    SparseTableRMinQ(vector<int> &vec)
    {
        MAXN = vec.size() ;
        LOG = log2_floor(MAXN) ;
        st = vector<vector<pair<int,int>>>(MAXN, vector<pair<int,int>>(LOG + 1));

        /* ------------------------------- base layer ------------------------------- */
        for (int i = 0; i < MAXN; i++) st[i][0] = {vec[i],i};

        /* ------------------------------ pre computing ----------------------------- */
        for (int j = 1; j <= LOG; j++)
            for (int i = 0; i + (1 << j) <= MAXN; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    inline pair<int,int> query(int L , int R)
    {
        int j = log2_floor(R - L + 1);
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }

    private:
    int log2_floor(unsigned long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
};

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree() {
        this->n = 0;
    }

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()){
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
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
};

class Euler {
    // @author : DIPANKAR KUMAR SINGH
    // TOUR 1 => Each Node Occour At Max two times in Euler's Path ... One at time of Entry , other at Exit
    // TOUR 2 => Zig - Zag Mode (node , c1 , node , c2 , node , node2 .....) : https://usaco.guide/CPH.pdf#page=174

    int n{0}, timer{0} , root{1};  // NOTE : 1 BASED GRAPH IS TAKEN SO ROOT 1 , change if graph is 0 based 
    vector<vector<int>> graph ;
    vector<int> tour1 , tour2 ; // Tour1 -> Every Node Twice // Tour2 --> Zig Zag Type
    vector<int> first_t1 , first_t2 , last_t1 , last_t2;
    vector<int> depth , depth_t2 ;
    // inTIme => first_t1 ----  OutTIme => last_t1

    /// BOTH Sub-Tree Query & Path Query happnes on Good ( Two Pass ) Type1 Euler Tour

    /// Task : up the firstSeen[v] ==> Implementatin : int Timeid = firstSeen[v] , tree.update(timeId,timeID , UPVal) ;  

    /// For SubTreeQuery // Only Up the FirstSeen(v) & !!! IMP : don't down the lastSeen(v) 
    FenwickTree subTree ;

    /// For PathTreeQuery // Do both Up firstSeen(v) && down lastSeen(v) 
    FenwickTree path ;

    // FOR LCA : 
    SparseTableRMinQ rangeMin;

    public :
    Euler(int totalNode) : n(totalNode + 1), graph(g) {
        depth = first_t1 = first_t2 = last_t1 = last_t2 = vector<int>(n) ;
        build();
        path = subTree = FenwickTree(tour1.size()) ;
        rangeMin = SparseTableRMinQ(depth_t2) ;
    }

    Euler(vector<vector<int>> _graph) : graph(_graph) , n(_graph.size()) { 
        // g size -> no_of_node + 1  // n => node + 1
        depth = first_t1 = first_t2 = last_t1 = last_t2 = vector<int>(n) ;
        build();
        path = subTree = FenwickTree(tour1.size()) ;
        rangeMin = SparseTableRMinQ(depth_t2) ;
    };

    Euler(vector<vector<int>> _graph, int _root) : graph(_graph) , n(_graph.size()){ 
        // g size -> no_of_node + 1  // n => node + 1
        depth = first_t1 = first_t2 = last_t1 = last_t2 = vector<int>(n) ;
        this->root = _root ;
        build();
        path = subTree = FenwickTree(tour1.size()) ;
        rangeMin = SparseTableRMinQ(depth_t2) ;
    };

    private: 
    void dfs(int node, int par) {
        tour1.push_back(node) ;
        tour2.push_back(node) ;

        for(int &child : graph[node]) { 
            if(child == par) continue ;
            depth[child] = depth[node] + 1 ;
            dfs(child,node) ;
            tour2.push_back(node) ;
        }

        tour1.push_back(node) ;
    }

    void build(){

        dfs(root,-1) ;

        for(int &node : tour2){
            depth_t2.push_back(depth[node]) ;
        }

        for(int i = 0 ; i < tour1.size() ; i++){
            last_t1[tour1[i]] = i ;
        }
        for(int i = 0 ; i < tour2.size() ; i++){
            last_t2[tour2[i]] = i ;
        }

        for(int i = tour1.size() - 1 ; i >= 0 ; i--){
            first_t1[tour1[i]] = i  ;
        }

        for(int i = tour2.size() - 1 ; i >= 0 ; i--){
            first_t2[tour2[i]] = i  ;
        }
    };
    

    public:
    /// @brief Lowest Common Ancestor
    /// @return tuor1[TimeId[min_depth]] in   firstSeen[node]  <= id <= lastSeen[node] 
    int lca(int a , int b) {

        function<bool(int,int)> isAncestor = [&](int x , int y)->bool{
            vector<int> &inTime  = this->first_t1 ;  // t1 = Good Two Pass
            vector<int> &outTime = this->last_t1 ;   // t1 = Good twp Pass 
            if(inTime[x] <= inTime[y] && outTime[x] >= outTime[y]) return true ; 
            return false ;
        };

        if(isAncestor(a,b)) return a ;
        if(isAncestor(b,a)) return b ;

        if(first_t1[a] > first_t1[b] ) {
            swap(a,b) ;
        }

        int l = first_t2[a] ; 
        int r = first_t2[b] ;

        auto [ min_depth , idx ] = rangeMin.query(l,r) ;
        int lca_node = tour2[idx] ;

        return lca_node ;
    }

    void addToNode(int node , int val){
        int l = first_t1[node] , r = last_t1[node] ;
        subTree.add(l,val)  ;
        path.add(l,val) ; path.add(r,-val) ;
    }

    /// @return sum of path from root to node
    int queryOnPath(int node){
        // from roo to node ...
        return path.sum(first_t1[node]) ;
    }
    
    /// @brief sum along the path ( a<---> b) 
    /// @return `sum(a,b) = SumRootTo(a) + SumRootTo(b) - 2*SumRootTo(LCA(a,b))`
    // !validate to check
    int queryOnPath(int a, int b) {
        if(first_t1[a] > first_t1[b]) swap(a,b) ;
        int c = lca(a,b) ;
        int val_at_lca = path.sum(first_t1[c],first_t1[c]) ;
        int res = queryOnPath(a) + queryOnPath(b) -  2*queryOnPath(c);
        res += val_at_lca ;
        return res;
    }

    int subTreeSum(int node){
        return subTree.sum(first_t1[node],last_t1[node]) ;
    }

    int distance(int nodeA , int nodeB){
        return depth[nodeA] + depth[nodeB] - 2 * depth[lca(nodeA,nodeB)] ;
    }

    /// @brief - firstSeen in Two pass Tour Euler
    /// @return - return timeId of node , it should be used in context of two Pass Euler Only
    int firstSeenTwoPass(int node){
        return first_t1[node] ;
    }

    /// @brief - lastSeen(node) in Two pass Tour Euler
    int lastSeenTwoPass(int node){
        return last_t1[node] ;
    } 

};

signed main(){   
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    int n ; cin >> n ;
    g = vector<vector<int>>(n + 1) ;
    vector<pair<int,int>> edges ; // for answering the query 

    for(int i = 0 ; i + 1 < n ; i++){
        int x , y ; 
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
        edges.push_back({x,y}) ;
    }

    Euler euler(g) ;
    
    int q ; cin >> q ;
    while(q--) {
        int a, b ; 
        cin >> a >> b ;
        int c = euler.lca(a,b) ;
        euler.addToNode(a,1) ;
        euler.addToNode(b,1) ;
        euler.addToNode(c,-2) ;
    }

    for(auto &[a , b] : edges){ 

        if(euler.firstSeenTwoPass(a) > euler.firstSeenTwoPass(b)) swap(a,b) ;
        cout << euler.subTreeSum(b) << " " ;
    }
    
}