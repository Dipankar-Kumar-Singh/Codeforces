#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


int const N = 5e5 + 110 ;
vector<int> seg[4*N] ;
vector<int> v ;
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

    merge(  begin(seg[2*n+1]) , end(seg[2*n+1]), 
            begin(seg[2*n+2]) , end(seg[2*n+2]), 
            back_inserter(seg[n]));
}

int query_equalto(int n , int s , int e , int l , int r , int val )
{
    if(e < l or s > r)
    {
        return 0 ;
    }

    if( l <= s   and  e <= r)
    {
        return upper_bound(all(seg[n]),val) - lower_bound(all(seg[n]),val) ;
    }

    int mid = (s+e)/2 ;

    return  (
                query_equalto(2*n+1, s, mid, l, r, val) +
                query_equalto(2*n+2, mid + 1, e, l, r, val)
            );
}

int query_greaterthan(int n , int s , int e , int l , int r , int val )
{
    if(e < l or s > r)
    {
        return 0 ;
    }

    if( l <= s   and  e <= r)
    {
        int id = upper_bound( begin(seg[n]), end(seg[n]) , val) - seg[n].begin();
        return (seg[n].size() - id) ;
    }

    int mid = (s+e)/2 ;

    return  (   
                query_greaterthan(2 * n + 1, s, mid, l, r, val) + 
                query_greaterthan(2 * n + 2, mid + 1, e, l, r, val) 
            ) ;
}

int query_lessthan(int n , int s , int e , int l , int r , int val )
{
    if(e < l or s > r)
    {
        return 0 ;
    }

    if( l <= s   and  e <= r)
    {
        int id = lower_bound( begin(seg[n]), end(seg[n]) , val) - seg[n].begin();
        return id ;
    }

    int mid = (s+e)/2 ;
    return  (
                query_lessthan(2 * n + 1, s, mid, l, r, val) + 
                query_lessthan(2 * n + 2, mid + 1, e, l, r, val)
            );
}

int count_inversion_using_segment_tree(int n)
{
    int inversion = 0;

   // Clearing the old stuff ..
    for (int i = 0; i < 4 * n + 100; i++)   seg[i].clear();
    
    build(0, 0, n - 1);

    // Inversion count from -> no of element that are present before whcih are bigger than current element
   
    for (int i = 1 ; i < n; i++)
    {
        inversion += (query_greaterthan(0, 0, n - 1, 0, i - 1 , v[i]));
    }

    return inversion;
}

signed main()
{   FAST  
    int n , q ; cin >> n >> q ;
    v.resize(n);  for(auto &x : v) cin >> x ;
    build(0,0,n-1) ;

    int ans = 0 ;

    while(q--)
    {
        int l , r ; cin >> l >> r ;
        l-- , r-- ; // zero basesd
        l++ ; r-- ; // l + 1 ..... r - 1 
        int val = v[l-1] ;
        if(query_greaterthan(0,0,n-1,l,r,val)==0) ans++  ;
    }

    cout << ans << nl ;
    

}

