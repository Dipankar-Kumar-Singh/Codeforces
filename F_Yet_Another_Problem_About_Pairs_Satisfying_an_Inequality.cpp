#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


class segmentTree {
public :
    int N = 5e5 ;
    vector<vector<int>> seg ;
    vector<int> v ;

    segmentTree(vector<int> &vec)
    {
        v = vec ; 
        int n  = v.size() ; N = n ;
        seg = vector<vector<int>>(4*N) ;
        build(0,0,n-1) ;
    }

    void build(int n , int s , int e )
    {
        if(s==e)
        {
            if (s + 1 > v[s])
                seg[n].push_back(v[s]);
            return ;
        }
        
        int mid = (s+e)/2 ;

        build(2 * n + 1, s, mid);
        build(2 * n + 2, mid + 1, e);

        merge(  
                begin(seg[2*n+1]) , end(seg[2*n+1]), 
                begin(seg[2*n+2]) , end(seg[2*n+2]), 
                back_inserter(seg[n])
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

        return (
            query_greaterthan(2 * n + 1, s, mid, l, r, val) +
            query_greaterthan(2 * n + 2, mid + 1, e, l, r, val));
    }

};



void solve()
{
    int n; cin >> n;
    vector<int> v(n);  for (auto &x : v) cin >> x;

    segmentTree tree(v);
    int ans = 0 ;

    for (int i = 0; i < n; i++)
    {
        int index = i + 1;
        if (index > v[i])
        {
            int l = i + 1; int r = n - 1 ; 

            int res =  tree.query_greaterthan(l, r, max(index,v[i]));
            ans += res ;
        }
    }

    cout << ans << nl  ;
}
signed main(){   FAST      TestCases      solve() ;  }



