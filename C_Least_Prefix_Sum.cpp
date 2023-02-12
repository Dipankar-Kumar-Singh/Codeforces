#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


class segmentTree
{
    public:
    int N = 0;
    vector<int> seg;
    vector<int> v;

    int mergeOP(int &a, int &b)
    {
        return a + b;
    }

    segmentTree(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
        build(0, 0, N - 1);
    }

    void update(int l, int r, int value)
    {
        update(0, 0, N - 1, l, r, value);
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
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }
    }

    void update(int n, int s, int e, int l, int r, int value)
    {
        if (s > r or e < l)
        {
            return;
        }
        if (s >= l and e <= r)
        {
            seg[n] += value;
            return;
        }

        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
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

        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);

        int ans = mergeOP(left, right);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return ans;
    }
};

void solve(int& __case__)
{
    int n , m ; 
    cin >> n >> m ;
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    m-- ;
    int ans = 0 ;


    if(n == 1)
    {
        cout << 0 << nl ;
        return ;
    }
    
    if(v[m] > 0)
    {
        ans++ ;
        v[m] = -v[m] ;
    }


    segmentTree tree(v) ;


    for(int i = 0 ; i < m; i++)
    {
        int curr = tree.query(0,i) ;
        int base = tree.query(0,m) ;

        if(curr < base)
        {
            ans++ ;
            int x = v[i] ;
            tree.update(i, i, -(2 * x));
            v[i] = -x ;
        }
    }


    for(int i = m + 1 ; i < n; i++)
    {
        int curr = tree.query(0,i) ;
        int base = tree.query(0,m) ;

        if(curr < base)
        {
            ans++ ;
            int x = v[i] ;
            tree.update(i, i, -(2 * x));
            v[i] = -x ;
        }
    }

    cout << ans << nl ;

    

    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
