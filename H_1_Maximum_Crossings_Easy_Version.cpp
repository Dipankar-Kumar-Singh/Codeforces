#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


int const N = 5e5 + 110 ;
vector<int> seg[4*N] ;
vector<int> v(N) ;

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

    merge(all(seg[2 * n + 1]), all(seg[2 * n + 2]), back_inserter(seg[n]));
}

int query(int n , int s , int e , int l , int r , int val )
{
    if(e < l or s > r)
    {
        return 0 ;
    }

    if( l <= s   and  e <= r)
    {
        auto &vec = seg[n] ;
        int id = lower_bound(all(vec), val) - vec.begin();
        return (vec.size() - id) ;
    }

    int mid = (s+e)/2 ;
    return (query(2 * n + 1, s, mid, l, r, val) + query(2 * n + 2, mid + 1, e, l, r, val));
}

int count_inversion_using_segment_tree(int n)
{
    int inversion = 0;

   // Clearing the old stuff ..
    for (int i = 0; i < 4 * n + 100; i++)   seg[i].clear();
    
    build(0, 0, n - 1);
   
    for (int i = 1 ; i < n; i++)
    {
        inversion += (query(0, 0, n - 1, 0, i-1, v[i]));
    }

    return inversion;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 0 ;i < n ;i++) cin >> v[i] ;

    int x = count_inversion_using_segment_tree(n);
    cout << x << nl;
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

