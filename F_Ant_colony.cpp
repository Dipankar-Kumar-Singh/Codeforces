#include <bits/stdc++.h>
#include "debugging.h"
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

const int N = 1e5 + 10 ;
pair < int , vector <int> > seg[4*N] ;
vector < int > v ;
pair<int,vector<int>> default_val = {0,{}} ;

void mrg(int n)
{
    int c1 = 2*n +1 , c2 = 2*n + 2 ;
    seg[n].first = gcd(seg[c1].first , seg[c2].first) ;
    merge(all(seg[c1].second),all(seg[c2].second),back_inserter(seg[n].second)) ;
}

void build(int n = 0  , int s = 0  , int e = v.size()-1 )
{
    if(s==e) {seg[n] = {v[s],{v[s]}} ; return ;  }
    
    int mid = (s+e)/2  ;
    build(2*n+1 , s , mid ) ;
    build(2*n+2 , mid+1 , e ) ;
    mrg(n) ;
}

int query_GCD(int n ,int s , int e , int l , int r)
{
    
    if(s>r or e<l ) return  0 ;
    if(s>=l and e<=r)
    {
        return seg[n].first ;
    }

    int mid = (s + e) / 2;
    return gcd(query_GCD(2 * n + 1, s, mid, l, r) , 
               query_GCD(2 * n + 2, mid + 1, e, l, r));
}

int query_no_of_elements_equal_TO_GCD(int n ,int s , int e , int l , int r , int G)
{
    if(s>r or e<l ) return  0 ;
    if(s>=l and e<=r)
    {
        vector<int> &vec = seg[n].second;
        return (upper_bound(all(vec),G) - lower_bound(all(vec),G)) ;
    }

    int mid = (s + e) / 2;
    return (query_no_of_elements_equal_TO_GCD(2 * n + 1, s, mid, l, r, G) +
            query_no_of_elements_equal_TO_GCD(2 * n + 2, mid + 1, e, l, r, G)) ;
    
}

signed main()
{
    FAST 
    int n ; cin >> n ; 
    v.resize(n)  ;  for(auto &x:v) cin >>  x ;   build() ;
    int m ; cin >> m ; 
    while(m--)
    {
        int x , y ; cin >> x >> y ; x-- , y-- ;
        int len = (y-x+1) ;
        int G  =  query_GCD(0,0,n-1,x,y) ;            
        cout << len - query_no_of_elements_equal_TO_GCD(0,0,n-1,x,y,G) << nl ;
    }
}

