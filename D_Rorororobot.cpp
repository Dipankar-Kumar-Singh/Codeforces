#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


class SegmentTree
{
public:
    int N = 1e6 + 10;
    vector<int> seg;
    vector<int> v;

    int const INF = numeric_limits<int>::max();
    int const MINF = numeric_limits<int>::min() ;

    void pass(int n)
    {
        seg[n] = max(seg[n * 2 + 1], seg[n * 2 + 2]);
    }

    void clean()
    {
        seg.clear();
        v.clear();
    }

    SegmentTree(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        build(0, 0, N - 1);
    }

    void update(int l, int r, int value)
    {
        update(0, 0, N - 1, l, r, value);
    }

    int querySum(int l, int r)
    {
        return querySum(0, 0, N - 1, l, r);
    }
    int queryMax(int l, int r)
    {
        return queryMax(0, 0, N - 1, l, r);
    }
    int queryMin(int l, int r)
    {
        return queryMin(0, 0, N - 1, l, r);
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

        if (s != e)  pass(n);
    }

    void update(int n, int s, int e, int l, int r, int value)
    {
        if (s > r or e < l)   return;

        if (s >= l and e <= r)
        {
            seg[n] = value ;
            return;
        }

        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);

        if (s != e)  pass(n);  
    }

    int querySum(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return 0 ;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }

        int mid = (s + e) / 2;
        int ans = (querySum(n * 2 + 1, s, mid, l, r) + querySum(n * 2 + 2, mid + 1, e, l, r));

        if (s != e) 
        {
            seg[n] = seg[2*n+1] + seg[2*n+2] ;
        }
        
        return ans;
    }

    int queryMax(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return MINF;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }

        int mid = (s + e) / 2;
        int ans = max(queryMax(n * 2 + 1, s, mid, l, r) , queryMax(n * 2 + 2, mid + 1, e, l, r));

        if (s != e)  pass(n);
        
        return ans;
    }

    int queryMin(int n, int s, int e, int l, int r)
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
        int ans = min(queryMin(n * 2 + 1, s, mid, l, r) , queryMin(n * 2 + 2, mid + 1, e, l, r));
        if (s != e)  pass(n);
    
        return ans;
    }

};


void solve()
{
   int n ; cin >> n ;
   int m ; cin >> m ;
   vector<int> v(m) ; for (auto &x : v) cin >> x ;

   SegmentTree seg(v) ;

   int q ; cin >> q ;
   while(q--)
   {
        int x , y ; cin >> x >> y ;
        int xx , yy ; cin >> xx >> yy ;
        int k ; cin >> k ;

        int s = min(y-1,yy-1) ; int e = max(y-1,yy-1) ;
        int h = seg.queryMax(s,e) ;
    
        if(x%k != xx%k or y%k != yy%k)
        {
            cout << "NO\n" ;
            continue; 
        }

        int rem = x%k ;
        int nx = n +  rem  -  (n%k) ;

        while (nx <= n) nx += k;
        while (nx > n)  nx -= k;

        cout << (nx > h ? "YES" : "NO" )<< nl ;
   }

}
signed main(){   FAST       solve() ;  }



