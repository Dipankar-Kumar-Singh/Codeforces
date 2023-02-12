    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

int op(int a, int b)
{
    return min(a,b) ;
}

inline int log2Up(int n) {
    int res = 0;
    while ((1 << res) < n) {
        res++;
    }
    return res;
}

class SqrtTree {
    private:
        int n, lg;
        vector<int> v;
        vector<int> clz;
        vector<int> layers;
        vector<int> onLayer;
        vector< vector<int> > pref;
        vector< vector<int> > suf;
        vector< vector<int> > between;
        
        void build(int layer, int lBound, int rBound) {
            if (layer >= (int)layers.size()) {
                return;
            }
            int bSzLog = (layers[layer]+1) >> 1;
            int bCntLog = layers[layer] >> 1;
            int bSz = 1 << bSzLog;
            int bCnt = 0;
            for (int l = lBound; l < rBound; l += bSz) {
                bCnt++;
                int r = min(l + bSz, rBound);
                pref[layer][l] = v[l];
                for (int i = l+1; i < r; i++) {
                    pref[layer][i] = op(pref[layer][i-1], v[i]);
                }
                suf[layer][r-1] = v[r-1];
                for (int i = r-2; i >= l; i--) {
                    suf[layer][i] = op(v[i], suf[layer][i+1]);
                }
                build(layer+1, l, r);
            }
            for (int i = 0; i < bCnt; i++) {
                int ans = 0;
                for (int j = i; j < bCnt; j++) {
                    int add = suf[layer][lBound + (j << bSzLog)];
                    ans = (i == j) ? add : op(ans, add);
                    between[layer][lBound + (i << bCntLog) + j] = ans;
                }
            }
        }
    public:
        inline int query(int l, int r) {
            if (l == r) {
                return v[l];
            }
            if (l + 1 == r) {
                return op(v[l], v[r]);
            }
            int layer = onLayer[clz[l ^ r]];
            int bSzLog = (layers[layer]+1) >> 1;
            int bCntLog = layers[layer] >> 1;
            int lBound = (l >> layers[layer]) << layers[layer];
            int lBlock = ((l - lBound) >> bSzLog) + 1;
            int rBlock = ((r - lBound) >> bSzLog) - 1;
            int ans = suf[layer][l];
            if (lBlock <= rBlock) {
                ans = op(ans, between[layer][lBound + (lBlock << bCntLog) + rBlock]);
            }
            ans = op(ans, pref[layer][r]);
            return ans;
        }
        
        SqrtTree(const vector<int>& v)
            : n((int)v.size()), lg(log2Up(n)), v(v), clz(1 << lg), onLayer(lg+1) {
            clz[0] = 0;
            for (int i = 1; i < (int)clz.size(); i++) {
                clz[i] = clz[i >> 1] + 1;
            }
            int tlg = lg;
            while (tlg > 1) {
                onLayer[tlg] = (int)layers.size();
                layers.push_back(tlg);
                tlg = (tlg+1) >> 1;
            }
            for (int i = lg-1; i >= 0; i--) {
                onLayer[i] = max(onLayer[i], onLayer[i+1]);
            }
            pref.assign(layers.size(), vector<int>(n));
            suf.assign(layers.size(), vector<int>(n));
            between.assign(layers.size(), vector<int>(1 << lg));
            build(0, 0, n);
        }
};

void solve()
{
    int n , k ;cin >> n >> k ;

    vector<pair<int,int>> dragon(n) ;

    for(auto &[ h , p ] : dragon) cin >> h ;
    for(auto &[ h , p ] : dragon) cin >> p ;

    sort(all(dragon)) ;

    vector<int> pv  , h;

    for (auto [health, power] : dragon)
            pv.push_back(power), h.push_back(health);

    SqrtTree treePower(pv) ;

    int damageDone = 0 ;
    int currK = k ;

    while(k > 0)
    {
        damageDone += k ;
        auto it = upper_bound(all(h), damageDone);

        auto id = it - h.begin();
        int alive = n - id ;

        if(alive <= 0 )  break;

        int MIN_POWER = treePower.query(id, n - 1);
        k -= MIN_POWER;

        if(k <= 0 ) break;
    }

    if (upper_bound(all(h), damageDone) == h.end())
    {
        cout << "YES\n" ;
    }
    else 
    {
        cout << "NO\n" ;
    }

}

signed main() { FAST TestCases solve(); }
