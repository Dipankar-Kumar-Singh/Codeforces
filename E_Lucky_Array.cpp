    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

vector<int> lucky(10000) ;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
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
};


class segmentTree
{
    //!  IMPORTANT :
    //TODO : CHANGE THE RETURN VALUE IN QUERY [ for {0,INF} seg out of range ] 

    public:
    int N = 0;
    vector<int> seg;
    vector<int> v;

    int mergeOP(int &a, int &b)
    {
        return a + b;

        // return min(a,b) ;
        // return max(a,b)  ;
        // return gcd(a, b);
        // return a ^ b ;
        // return a | b ;
        // return a & b ;
    }

    segmentTree(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
        build(0, 0, N - 1);
    }

    void update(int id,  int value)
    {
        update(0, 0, N - 1, id, value);
    }

    int query(int l, int r)
    {
        return query(0, 0, N - 1, l, r);
    }

    void build(int n, int s, int e)
    {
        if (s == e)
        {
            seg[n] = lucky[v[s]];
            return;
        }

        int mid = (s + e) / 2;
        build(n * 2 + 1, s, mid);
        build(n * 2 + 2, mid + 1, e);

        if (s != e)
        {
            seg[n] = seg[n * 2 + 1] + seg[n * 2 + 2];
        }
    }

    void update(int n, int s, int e, int id , int value)
    {
        if (s == e)
        {
            v[s] += value ; 
            seg[n] = lucky[v[s]];
            return;
        }

        int mid = (s + e) / 2;
        if (id <= mid)
            update(n * 2 + 1, s, mid, id, value);
        else
            update(n * 2 + 2, mid + 1, e, id, value);

        if (s != e)
        {
            seg[n] = seg[n * 2 + 1] +  seg[n * 2 + 2];
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return 0;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;

        int ans = query(n * 2 + 1, s, mid, l, r) + query(n * 2 + 2, mid + 1, e, l, r);

        if (s != e)
        {
            seg[n] = seg[n * 2 + 1] + seg[n * 2 + 2];
        }

        return ans;
    }
};



void markLuckyDFS(int num)
{
    if(num > 10000) return ;
    lucky[num] = 1 ;
    int num1 = num * 10 + 4 ;
    int num2 = num * 10 + 7 ;

    markLuckyDFS(num1) ;
    markLuckyDFS(num2) ;
}


void solve()
{
    int n , m ; cin >> n >> m ;
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    markLuckyDFS(4) ; markLuckyDFS(7) ;

    vector<int> maskLucky(n) ;
    for(int i = 0 ; i < n;  i++) maskLucky[i] = lucky[v[i]] ;
    // FenwickTree tree(maskLucky) ;


    segmentTree tree(v) ;

    while(m--)
    {
        string query ; cin >> query ;
        int l ,r ; 
        cin >> l >> r ;
        l-- , r-- ;
        if(query == "count")
        {
            // cout << tree.sum(l,r)  << nl;

            cout << tree.query(l,r) << nl ;
        }
        else 
        {
            int val ; cin >> val ;
            for(int i = l ; i <= r ; i++)
            {
                // if( lucky [v[i]] ) tree.add(i,-1) ;
                // v[i] += val ;
                // if( lucky[v[i]] ) tree.add(i,1) ;
                
                tree.update(i,val) ;
            } 
        }   
    }
}

signed main() { FAST  solve(); }
