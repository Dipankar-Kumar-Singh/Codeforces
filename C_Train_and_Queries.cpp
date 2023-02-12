#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


// int const INF  = 1e18 ;
int test = 0 ;


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

    int query_equalto(int l, int r, int val)
    {
        return query_equalto(0,0,N-1,l,r,val) ;
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

        return (
            query_equalto(2 * n + 1, s, mid, l, r, val) +
            query_equalto(2 * n + 2, mid + 1, e, l, r, val));
    }

    
};


void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    int q ; cin >> q ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 
    segmentTree seg(v) ;

    map<int,int> loc ;
    for(int i = n -1  ; i >= 0 ; i--)
    {
        loc[v[i]] = i + 1;
    }

    while (q--)
    {
        int x , y ; cin >> x >> y ;
        int l = loc[x] - 1;
        int r = n - 1 ;

        if(loc[x]==0 or loc[y]==0)
        {
            cout << "NO\n" ;
            continue ;
        }
        
        else if(seg.query_equalto(l+1,r,y))
        {
            cout << "YES\n" ;
        }

        else 
        {
            cout << "NO\n" ;
        }
        
    }
    


    

    

}

signed main(){  FAST    TestCases    solve() ; }