#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

// NUDE SEGMENT TREE WOKRED .... NAGA WOKING... 
// SAME LOGIC .. NO TLE .... 

int test = 0 ;
int const N = 5e5 + 10 ;
vector<int> v(N) ;
vector<int> seg(4*N) ;

void build(int n , int s, int e)
{
    if(s==e)
    {
        seg[n] = v[s] ;
        return ;
    }

    int mid = (s + e) / 2 ;

    build(2*n + 1 , s , mid ) ;
    build(2*n + 2 , mid + 1, e) ;

    if(s != e)
    {
        seg[n] = gcd(seg[2*n + 1], seg[2*n + 2]);
    }
}

int query(int n , int s , int e , int l , int r)
{
    if( s > r or e < l )
    {
        return 0 ;
    }

    if (s >= l and e <= r)
    {
        return seg[n] ;
    }

    int mid = (s + e) / 2 ;

    int a = query(2 * n + 1, s, mid, l, r);
    int b = query(2 * n + 2, mid + 1, e, l, r);

    return gcd(a, b);
}


bool isPossible(int len , int n )
{
    for(int i = 0 ; i + len <= n ; i++)
    {
        if (query(0, 0, n - 1 , i, i + len - 1) > 1)  return 1;
    } 

    return 0 ;
}

void solve()
{
    int n ; cin >> n ;
    vector<int> vec(n) ; for(auto &x : vec) cin >> x ;

    if(n==1)
    {
        cout << 1 << nl ;
        return ;
    }

    vector<int> d;
    for (int i = 0; i + 1 < n ; i++)
        d.push_back(abs(vec[i] - vec[i + 1]));

    
    int longest_seq = 0 ;
    n = d.size() ;

    for(int i = 0 ; i < n ; i++) v[i] = d[i] ;
    for(int i = 0; i < 4*n ; i++) seg[i] = 0 ;
    build(0,0,n-1) ;

    int l = 0 , r = n + 1 ; 
    while(r - l > 1 ) 
    {
        int mid = midpoint(l,r) ;
        int sz = mid ;

        if(isPossible(mid,n))
        {
            longest_seq = max(longest_seq,mid) ;
            l = mid ;
        }
        else 
        {
            r = mid ;
        }
    }

    cout << longest_seq + 1 << nl ;
}

signed main(){  
    FAST    
    TestCases    solve() ; 
}