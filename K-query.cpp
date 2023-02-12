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

class segmentTree {
public :
    int N = 5e5;
    vector<vector<int>> seg;
    vector<int> v;

    segmentTree(vector<int> &vec)
    {
        v = vec;
        N = v.size();
        seg = vector<vector<int>>(4 * N);
        build(0, 0, N - 1);
    }

    void build(int n, int s, int e)
    {
        if (s == e)
        {
            seg[n].push_back(v[s]);
            return;
        }
        
        int mid = (s + e) / 2;
        build(2 * n + 1, s, mid);
        build(2 * n + 2, mid + 1, e);

        merge(
                begin(seg[2 * n + 1]), end(seg[2 * n + 1]),
                begin(seg[2 * n + 2]), end(seg[2 * n + 2]),
                back_inserter(seg[n])
             );
    } 

    int query_equalto(int l, int r, int val)
    {
        return query_equalto(0, 0, N - 1, l, r, val);
    }

    int query_equalto(int n, int s, int e, int l, int r, int val)
    {
        if (e < l or s > r)
        {
            return 0;
        }

        if (l <= s and e <= r)
        {
            auto [ps, pe] = equal_range(begin(seg[n]), end(seg[n]), val);
            return pe - ps;
        }

        int mid = (s + e) / 2;

        return(
                query_equalto(2 * n + 1, s, mid, l, r, val) +
                query_equalto(2 * n + 2, mid + 1, e, l, r, val)
              );
    }

    int query_greaterthan(int l, int r, int val)
    {
        return query_greaterthan(0, 0, N - 1, l, r, val);
    }

    int query_greaterthan(int n, int s, int e, int l, int r, int val)
    {
        if (e < l or s > r)
        {
            return 0;
        }

        if (l <= s and e <= r)
        {
            int id = upper_bound(begin(seg[n]), end(seg[n]), val) - seg[n].begin();
            return (seg[n].size() - id);
        }

        int mid = (s + e) / 2;

        return(
                query_greaterthan(2 * n + 1, s, mid, l, r, val) +
                query_greaterthan(2 * n + 2, mid + 1, e, l, r, val)
              );
    }

    int query_lessthan(int l, int r, int val)
    {
        return query_lessthan(0, 0, N - 1, l, r, val);
    }

    int query_lessthan(int n, int s, int e, int l, int r, int val)
    {
        if (e < l or s > r)
        {
            return 0;
        }

        if (l <= s and e <= r)
        {
            int id = lower_bound(begin(seg[n]), end(seg[n]), val) - seg[n].begin();
            return id;
        }

        int mid = (s + e) / 2;
        return (
                query_lessthan(2 * n + 1, s, mid, l, r, val) +
                query_lessthan(2 * n + 2, mid + 1, e, l, r, val)
               );
    }

    int count_inversion_using_segment_tree()
    {
        int inversion = 0;
        for (int i = 1; i < N; i++)
        {
            inversion += (query_greaterthan(0, 0, N - 1, 0, i - 1, v[i]));
        }
        return inversion;
    }
};

void solve()
{
    int n ; cin >>  n;
    vector<int> v(n) ; for(auto &x : v) cin >> x ;

    segmentTree tree(v) ;

    int q ; cin >> q ;
    while(q--)
    {
        int i , j , k ; 
        cin >> i >> j >> k ;
        i-- , j-- ;
        cout << tree.query_greaterthan(i,j,k) << nl ;
    }
    
}

signed main() { FAST  solve(); }
