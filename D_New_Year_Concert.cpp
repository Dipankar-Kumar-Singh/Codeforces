#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 
const int N = 2e5 + 100 ;

vector<int> seg(N*4) ;
vector<int> v ;

void build(int n ,  int s , int e )
{
    if(s==e)
    {
        seg[n] = v[s] ;
        return ; 
    }

    int mid = (s+e)/2 ;

    build(2*n+1 , s , mid ) ;
    build(2*n+2 , mid + 1  , e ) ;

    seg[n] = gcd(seg[2*n+1] ,seg[2*n+2]) ;

    return ;
}

int query_gcd(int n ,int s ,int e , int l ,int r)
{

    if( e < l or r < s){ return 0 ; }

    if( l<=s and e<=r )
    {
        return seg[n] ;
    }

    int mid = (s+e)/2 ;

    return gcd(query_gcd(2 * n + 1, s, mid, l, r),
               query_gcd(2 * n + 2, mid + 1, e, l, r));
}

void update(int n ,int s ,int e , int id , int val)
{
    if(s==e)
    {
        seg[n] = val ;
        return ;
    }

    int mid = (s+e)/2 ;

    if(id<=mid) update(2*n+1,s,mid,id,val) ;
    else update(2*n+2 , mid + 1 , e , id , val) ;

    seg[n] = gcd(seg[2*n+1],seg[2*n+2]) ;
}

void segment_tree_sol()
{
    int n;  cin >> n ; 
    v.resize(n) ; 

    for(auto &x : v ) cin >> x ; 

    build(0,0,n-1) ;
    vector<int> ans(n) ;

    for(int i =  0 ; i < n ; i++)
    {

        if(v[i] == 1)
        { 
            ans[i]++ ; 
            continue ;
        } 

        int l = i , r = n ;
        while (r-l>1)
        {
            int mid = (l+r)/2 ;
        
            int G = query_gcd(0,0,n-1,i,mid) ;

            int len = mid - i + 1 ;

            if( G >= len) 
            {
                if (G == len)
                {
                    update(0,0,n-1,mid,P) ;
                    ans[mid]++ ;
                    v[mid] = P ;
                    break ;
                }

                l = mid ; 
            }
            else r = mid ; 
        }
    }

    for(int i = 0 ; i < n; i++)
    {
        if(i) ans[i] += ans[i-1] ; 
        cout << ans[ i ] << ' ' ; 
    }

}

void brute_force()
{
    int n; cin >> n; vector<int> v(n);
    for (auto &x : v) cin >> x;
    vector<int> marked(n);

    for (int i = 0; i < n; i++)
    {
        int G = v[i];
        if (G == 1)
        {
            marked[i] = 1;
            v[i] = P;
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            G = gcd(G, v[j]);
            int len = j - i + 1;
            if (G == len)
            {
                v[j] = P;
                marked[j] = 1;
                i = j;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i - 1 >= 0)
            marked[i] = marked[i - 1] + marked[i];
    }

    for (auto x : marked)
        cout << x << " ";
    cout << nl;

}


signed main()
{
    FAST

    segment_tree_sol() ;

}

