#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


int const N = 1e5 + 10;
vector < int > seg (4*N) ;
vector < int > lazy (4*N) ;

vector<int> a , b ;

void solvelazy(int n , int s , int e)
{
    if(lazy[n] == 0 ) return ;

    seg[n] = lazy[n] ; 
    if(s!=e)
    {
        lazy[2*n+1]  = lazy[n] ; 
        lazy[2*n+2] =  lazy[n] ;
    }

    lazy[n] = 0  ;
}

void update(int n , int s ,int e , int l , int r , int val)
{
    solvelazy(n,s,e) ;

    if(s>r or r<l) return ;
    if(s>= l and e<=r)
    {
        lazy[n] = val ; 
        solvelazy(n,s,e) ;
        return ; 
    }

    int mid = (s+e)/2 ;

    // FROM UNSPOPABLE SIR --> BETTER TRICK THAN CP ALogrithm ... ///
    // IN LAZY Prop for seg --> ASSIGNMENT -->
    //  Only call update if that part contains some / full part of our required range 
    // 

    if(l<=mid) 
        update(n*2 + 1, s, mid, l, r, val);
    if(r>mid) 
        update(n*2 + 2, mid + 1, e, l, r, val);
}

int query(int n , int s , int e , int id)
{
    solvelazy(n,s,e) ;

    if(s==e and s==id) 
    {
        solvelazy(n,s,e) ;
        return seg[n] ;
    }

    int mid = (s+e)/2  ;
    
    solvelazy(2*n+1,s,mid) ;
    solvelazy(2*n+2,mid+1,e) ;
    
    if(id<=mid) return query(2 * n + 1, s, mid, id);
    return query(2 * n + 2, mid + 1, e, id);
} 


signed main()
{
    FAST 

    int n , m ; cin >> n >> m ;
    a.resize(n) , b.resize(n) ;
 
    for(auto &x : a) cin >> x ;
    for(auto &x : b) cin >> x ;
    vector<int> Qx(N) , Qy(N) , Qlen(N) ; 

    for(int q = 1 ; q <= m ; q++)
    {
       int t ; cin >> t ;
        if(t==2)
        {
            int i ; cin >> i ;  i--;
            int color = query(0, 0, n - 1, i);
            if(color) 
            {
                int x = Qx[color]  , y = Qy[color] , len = Qlen[color] ;
                cout << a[x+i-y] << nl ;
            }
            else {cout << b[i] << "\n" ;}
        } 

        else if(t==1)
        {
            int x, y, len;
            cin >> x >> y >> len;    y--, x--;

            Qx[q] = x, Qy[q] = y, Qlen[q] = len;

            int start = y, end = y + len - 1;
            update(0, 0, n - 1, start, end, q);
        }
    }

}

