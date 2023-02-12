#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

const int N = 1e6 + 5 ; 
vector <int> seg [N<<2] ;
vector<int> v ;

void build(int n , int s , int e )
{
    if(s==e)
    {
        seg[n].push_back(v[s]) ;
        return ;
    }

    // int mid = midpoint(s,e) ;
    int mid = (s + e )/ 2 ;
  
    build(n * 2 + 1, s, mid);
    build(n * 2 + 2, mid + 1, e);

    merge(all(seg[(n*2) + 1]),all(seg[(n*2) + 2]),back_inserter(seg[n])) ;
    // sort(all(seg[n])) ;
}

int query(int n , int s , int e  , int l , int r , int f )
{
   
    if(s > r or e < l) return 0 ;
    if(s >= l and e <= r)
    {
        return (lower_bound(all(seg[n]),f) - seg[n].begin()) ;
    }

    // int mid = midpoint(s,e) ;
    int mid = (s + e )/ 2 ;

    return (query((2 * n) + 1, s, mid, l, r, f) +
            query((2 * n) + 2, mid + 1, e, l, r, f));
}


signed main()
{
    FAST 

    int n ; cin >> n ;
    v.resize(n) ;

    vector<int> a(n) ; 
    for(int &i : a ) cin >> i ; 

    map<int,int> fr_front , fr_back ;

    for (int i = n - 1; i >= 0; i--)
    {
        v[i] = ++fr_back[a[i]];
    }

    build(0,0,n-1) ;

    long long ans = 0 ;
    for(int  i = 0 ; i < n ; i++)
    {
        ans += query(0,0,n-1,i+1,n-1,++fr_front[a[i]]) ;
    }

    cout << ans ;

}
 