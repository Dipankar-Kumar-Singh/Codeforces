#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;

class segmentTree
{
    public:
    int N = 0;
    vector<int> seg;
    vector<int> v;
    segmentTree(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
        build(0, 0, N - 1);
    }

    int query(int l, int r)
    {
        return query(0, 0, N - 1, l, r);
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
            seg[n] = min(seg[n * 2 + 1], seg[n * 2 + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return INF;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;

        if (s != e)
        {
            seg[n] = min(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return min(query(n * 2 + 1, s, mid, l, r),  query(n * 2 + 2, mid + 1, e, l, r));;
    }
};


void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ;

    vector<int> p(n + 2);
    partial_sum(all(v), p.begin() + 1);
    segmentTree tree(p);

    vector<int> pp(n + 10);
    partial_sum(all(p), pp.begin() + 1);

    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
            continue;

        int l = i, r = n + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (tree.query(i + 1, mid) - p[i] >= 0)
                l = mid;
            else
                r = mid;
        }

        int L = i + 1, R = l;
        //  One Based Indexing ..
        int range = R - L + 1;
        int sumP = pp[R + 1] - pp[L] - (range * p[L - 1]);
        ans += sumP;
    }

    print(ans);
}

signed main(){  FAST    TestCases    solve() ; }