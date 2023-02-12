#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int const N = 1e6+10 ;
vector < int > seg[N*4+100] ;
vector<int> v;

void build(int n , int s , int e)
{
    if(s==e )
    {
        seg[n].push_back(v[s]) ;
        return ;
    }

    int mid = (s+e)/2 ;

    build(2 * n + 1, s, mid);
    build(2 * n + 2, mid + 1, e);

    merge(all(seg[2*n+1]),all(seg[2*n+2]), back_inserter(seg[n]) ) ;
}

long long query(int n , int s , int e , int l , int r , int val ,  bool type)
{
    if(s > r or e < l ) return 0 ;

    if(s>=l and e <= r)
    {
        int id = lower_bound(all(seg[n]),val)  - seg[n].begin();

        if(type == 1)
        {
            // no of elemt greater than val 
            return seg[n].size() - id  ;
        }

        else 
        {
            // no of element less than val ...
            return id ; 
        }
    }

    int mid = (s+e) /2 ;
    return (query(2 * n + 1, s, mid, l, r, val, type) +
            query(2 * n + 2, mid + 1, e, l, r, val, type));


}

signed main()
{
    FAST 

    int n ; cin >> n ; 

    v.resize(n) ;

    for(int &i : v ) cin >> i ; 

    build(0,0,n-1) ;

    long long ans = 0 ;

    for(int i = 1 ; i < n - 1 ; i ++)
    {
        long long  a = query(0,0,n-1,0,i-1,v[i],1) ;
        long long  b = query(0,0,n-1,i+1,n-1,v[i],0) ;

        ans +=  (a*b) ;
    }

    cout << ans << "\n" ;



    
    


}

