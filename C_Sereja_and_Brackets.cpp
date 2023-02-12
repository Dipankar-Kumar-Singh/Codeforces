#include <bits/stdc++.h>
using namespace std;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

class SEG{
public:
    int len{};
    int left{}, right{};
};


const int N = 1e6 + 10 ;
SEG seg[4*N] ;
string ss ;


void mrg(SEG &p , SEG c1 , SEG c2)
{
    p.len  = c1.len + c2.len ;

    //  left, right;          left   right;
    //   ))))     (((          )   ((((

    int cm = min(c1.right , c2.left) ;

    p.right = c1.right - cm + c2.right ; 
    p.left = c1.left + c2.left - cm ;

    p.len += (cm*2) ;
}

void build(int n , int s , int e )
{
    if(s==e)
    {
        int rr = 0 , ll = 0 ;
        if(ss[s]==')')  ll++ ; else rr++ ;
        seg[n] = {0,ll,rr} ;
        return ;
    }

    int mid = (s+e)/2 ;

    build(2 * n + 1, s, mid);
    build(2 * n + 2, mid + 1, e);

    auto &c1 = seg[2*n+1] ;
    auto &c2 = seg[2*n+2] ;
    mrg(seg[n] , c1 ,c2) ;

}


SEG  query(int n , int s , int e , int l , int r )
{
    SEG temp ;
    if(s>r or e < l ) return temp ;
    if(s>= l and e <= r)
    {
        return seg[n]  ;
    }

    int mid = (s + e)/2 ;


    auto c1 =   query(2 * n + 1, s, mid, l, r);
    auto c2 =   query(2 * n + 2, mid + 1, e, l, r);

    SEG p ;
    mrg(p,c1,c2) ;

    return p ;
}


signed main()
{
    FAST 
    cin >> ss ;     int n = ss.size() ;
    build(0,0,n-1) ;

    t_case
    {
        int l ,r  ; cin >> l  >> r ;
        l-- , r-- ;
        auto S = query(0,0,n-1,l,r) ;
        cout << S.len << nl;                                                         
    }

}

