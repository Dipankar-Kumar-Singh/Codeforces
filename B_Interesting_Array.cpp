#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

// NOTES :::::: SEGMENT may AND ho raha hai .. thus ... baki bits key matlab nahi ..
// if demand 1st , 4th and 10th bit ki hai .. we just need to foucus on 1,4, 10 ..
// 2,3,5,6,7,9 --> enn saab bits sey koi matlab nahhi ......[ but agar same behavior raha on whole l to r seq then it is a problem.... ]
// we hoping .. even if non - requred bits are on ... but combining with other number in segmnet will turn them off and finally .. we will have out desiered result //
// bas REQUIED BIS on rehna cahiye .. and rest all others ko bhi off ---> but making 0 is easy but making bit 1 is hard ..
// thus .. kisi bhi overlaping region mai ... OR karna acha raheyga .. OR --> NAHI YE OLD BITS KO OFF KARTA HAI .. NA HI NEW BITS KO OFF ..
// OR --> DONO KI CONDITION EEK SAATH satisfy kar dega ...
// thus ... rage update mai .. range pey OR { seg = seg|new_val }  kar do .. 
// BAS QUERY mai { AND & } karna hai .. to check for out requied condition ...


//          ____________ 2 2 2 2 2 2 2 2 2 2 _________________
//          _______3 3 3 3 3 3 2 2 2 2 2 2 2 _________________
//          _______3 3 3[_____]2 2 2 2 2 2 2 _________________
//                        |
//                        V

//                    over laping region .. 2 and 3 are both overlaopoing ...
//                  in this region .. do (2|3) --> 2 or 3 --> dono range ki baat maan lo  


auto ALL_ONE = bitset<35>() ;
int MAXXX_ONE ;   // 1111111111111111111111111111111111

int const N = 1e5 + 10;     
vector < int > seg (4*N) ;  
vector < int > lazy (4*N) ;

void solvelazy(int n , int s , int e)
{
    if(lazy[n] == 0 ) return ;
    seg[n] |=  lazy[n] ; 
    if(s!=e)
    {
        lazy[2*n+1] |= lazy[n] ; 
        lazy[2*n+2] |=  lazy[n] ;
    }
    lazy[n] = 0  ;
}

void update(int n, int s, int e, int l, int r, int val)
{
    solvelazy(n,s,e) ;
    if(s>r or r<l) return ;
    if (s >= l and e <= r)
    {
        lazy[n] = val ; 
        solvelazy(n,s,e) ;
        return ;
    }
    int mid = (s+e)/2 ;
    if(l<=mid) 
        update(n*2 + 1, s, mid, l, r, val);
    if(r>mid) 
        update(n*2 + 2, mid + 1, e, l, r, val);
}
 
int query(int n , int s , int e , int l , int r)
{
    solvelazy(n,s,e) ;
    if(s > r or e < l )  return MAXXX_ONE ;
    if( l <= s  and e <= r) 
    {
        solvelazy(n,s,e) ;
        return seg[n] ;
    }
 
    int mid = (s+e)/2  ;
    return (query(2 * n + 1, s, mid, l , r) &
            query(2 * n + 2, mid + 1, e, l , r));

} 

signed main()
{
    for(int i = 0 ; i < 34 ; i++) ALL_ONE[i] = 1 ;
    MAXXX_ONE = ALL_ONE.to_ullong() ;

    FAST 
    int n , m ; cin >> n >> m ; 
    int qqq = m ;
    vector<tuple<int,int,int>> req ; 
    while (qqq--)
    {
        int  l , r , x ; cin >> l >> r >> x ;
        l-- , r-- ;
        req.push_back({l,r,x}) ;
        update(0,0,n-1,l,r,x) ;
    }

    bool possible = 1 ;

    for(auto &[l,r,x]:req)
        if(query(0,0,n-1,l,r)!=x)
            possible = 0 ;
        
    if(!possible) 
    {
        cout << "NO" ;
        exit(0) ;
    }

    else cout << "YES\n" ;

    for(int i = 0 ; i < n ; i++)
    {
        cout << query(0,0,n-1,i,i) << " " ;
    }

}

