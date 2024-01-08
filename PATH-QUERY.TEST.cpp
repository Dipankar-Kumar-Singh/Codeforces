#include "bits/stdc++.h"
using namespace std;
#include"/home/dk/debugging.h"

const int N = 2e5 + 5;
const int D = 19;
const int S = (1 << D);

int n, q, v[N];
vector<vector<int>> g(N);

int sz[N], p[N], dep[N];
int st[S], id[N], tp[N];

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

int dfs_sz(int cur, int par) {
	sz[cur] = 1;
	p[cur] = par;
	for (int chi : g[cur]) {
		if (chi == par) continue;
		dep[chi] = dep[cur] + 1;
		p[chi] = cur;
		sz[cur] += dfs_sz(chi, cur);
	}
	return sz[cur];
}

int ct = 1;

void dfs_hld(int cur, int par, int top) {
	id[cur] = ct++;
	tp[cur] = top;
	update(id[cur], v[cur]);
	int h_chi = -1, h_sz = -1;
	for (int chi : g[cur]) {
		if (chi == par) continue;
		if (sz[chi] > h_sz) {
			h_sz = sz[chi];
			h_chi = chi;
		}
	}
	if (h_chi == -1) return;
	dfs_hld(h_chi, cur, top);
	for (int chi : g[cur]) {
		if (chi == par || chi == h_chi) continue;
		dfs_hld(chi, cur, chi);
	}
}

int path(int x, int y) {
	int ret = 0;
	while (tp[x] != tp[y]) {
		if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
		ret = max(ret, query(id[tp[x]], id[x]));
		x = p[tp[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ret = max(ret, query(id[x], id[y]));
	return ret;
}

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

vector<int> parent, depth, heavy, head, pos;
int cur_pos { };
void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

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

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(1, adj);
    decompose(1, 1, adj);

    dbg(head)
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for (int i = 2; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs_sz(1, 1);
	dfs_hld(1, 1, 1);

    int(g) ;

    cerr << "Head " ;
    for(int i = 0 ; i <= n ;i++) {
        cerr << tp[i] << " " ;
    }

	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int s, x;
			scanf("%d%d", &s, &x);
			v[s] = x;
			update(id[s], v[s]);
		} else {
			int a, b;
			scanf("%d%d", &a, &b);
			int res = path(a, b);
			printf("%d ", res);
		}
	}
}