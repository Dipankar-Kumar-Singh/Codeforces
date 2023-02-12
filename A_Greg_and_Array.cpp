#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

const int N = 5e5 ;
vector<int> seg(N) , v(N) , lazy;

void build(int n , int s , int e )
{
    if(s==e)
    {
        seg[n] = v[s] ;
        return ;
    }

    int mid =( s+e )/ 2 ;
    build(2*n+1 , s , mid ) ; 
    build(2*n+2,mid+1,e) ;

    seg[n] = seg[2*n+1] + seg[2*n+2]  ; 
}

void solvelazy(int n , int s , int e)
{
    if(lazy[n]==0) return ;
    seg[n] = lazy[n] ;
    if(s!=e)
    {
        lazy[2*n+1] = seg[n] ;
        lazy[2*n+2] = seg[n] ;
    }
    lazy[n]  =  0 ;
}

void update(int n , int s, int e , int l , int r , int val)
{
    solvelazy(n,s,e) ;
    if(e<l or s>r) return ;
    if(s>=l and e<=r)
    {
        lazy[n] += val ;
        solvelazy(n,s,e) ;
        return ;
    }

    int mid = (s+e)/2 ; 

    update(2*n+1,s,mid,l,r,val) ;
    update(2*n+2,mid+1,e,l,r,val) ;
}


int query(int n ,int s , int e , int id)
{
    solvelazy(n,s,e) ;

    if(s==id)
    {
        return seg[n] ;
    }

    int mid = (s+e)/2 ;
    if(id<=mid) return query(2*n+1,s,mid,id) ;
    else return query(2*n+2,mid,e,id) ;
 
    return 0 ;
}

signed main()
{   
    FAST  

    int n , m , k ; 
    cin >> n >> m >> k ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    } 

 
  


}

