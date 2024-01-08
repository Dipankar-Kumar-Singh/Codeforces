#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

vector<int> values;

int const N = 2e5 + 100;
int const S = 1e6 ;
int sz[N] ;
int st[S] ;
int n ;

void update(int idx, int val) {
	st[idx += n] = val;
	for (idx /= 2; idx; idx /= 2) st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}

int query(int lo, int hi) {
	int ra = 0, rb = 0;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, st[lo++]);
		if (hi & 1) rb = max(rb, st[--hi]);
	}
	return max(ra, rb);
}

vector<vector<int>> g ;
vector<int> depth , heavy , head , parent ,pos ;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
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

int cur_pos = 0 ;
void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

int query_path(int a , int b){
    int res = 0 ;
    for(; head[a] != head[b] ; b = parent[head[b]]) {
        if(depth[head[a]] > depth[head[b]]) swap(a,b) ;
        res = max(res , query(pos[head[b]] , pos[b]) ) ;   
    }

    if(depth[a] > depth[b]){ 
        swap(a,b) ;
    }

    res = max( res , query(pos[a] , pos[b])) ;
    return res ;
};

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n + 1);
    depth = vector<int>(n + 1);
    heavy = vector<int>(n, -1);
    head = vector<int>(n + 1);
    pos = vector<int>(n + 1);
    cur_pos = 0;

    dfs(1, adj);
    decompose(1, 1, adj);
}

signed main()
{   
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n ;
    int q ; cin >> q ;

    g = vector<vector<int>>(n + 1) ;
    values = vector<int>(n + 1) ;
  
    for(int i = 1 ; i <= n ; i++) cin >> values[i]  ;

    for(int i = 1 ; i <= n - 1 ; i++){
        int x , y ; cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    init(g) ;

    for(int i = 1 ; i <= n ; i++){
        update(pos[i],values[i]) ;
    }

    for(int i = 0 ; i < q ; i++){
        int t ; cin >> t ; 
        if(t == 1){
            int node ; int val ;
            cin >> node >> val ;
            update(pos[node],val) ;
        }
        else {
            int a , b ;
            cin >> a >> b ;
            cout << query_path(a,b)  << " ";
        }
    };  

}

/**^%#*&
            ██████╗ ██╗██████╗  █████╗ ███╗   ██╗██╗  ██╗ █████╗ ██████╗ 
            ██╔══██╗██║██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝██╔══██╗██╔══██╗
            ██║  ██║██║██████╔╝███████║██╔██╗ ██║█████╔╝ ███████║██████╔╝
            ██║  ██║██║██╔═══╝ ██╔══██║██║╚██╗██║██╔═██╗ ██╔══██║██╔══██╗
            ██████╔╝██║██║     ██║  ██║██║ ╚████║██║  ██╗██║  ██║██║  ██║
            ╚═════╝ ╚═╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
*/                                                          
