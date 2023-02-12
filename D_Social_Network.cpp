#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

struct DSU {
    vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve()
{
    int n ; int m ; cin >> n >> m ;
    DSU g(n+10) ;
    int extra = 0 ;

    for(int i = 0 ; i < m ; i++) 
    {
        int x , y ; cin >> x >> y ;
        extra += (!g.merge(x,y)) ;

        vector<int> a ;
        for(int v = 1 ; v <= n ; v++)
        {
            if (g.leader(v)== v)
                a.push_back(g.siz[v]);
        }

        sort(all(a)) ; reverse(all(a)) ;
        cout << accumulate(a.begin(), a.begin() + extra + 1, 0) - 1 << "\n";
    }
}
signed main(){   FAST  solve() ;  }



