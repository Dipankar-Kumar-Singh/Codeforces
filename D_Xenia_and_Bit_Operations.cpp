#include <bits/stdc++.h>
using namespace std;
#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 

const int N = 1e5 + 1000 ;
vector<int> v , seg (4*N) ;

int hight = 0 ;

int opration(int node, int h)
{

    int X = (seg[node * 2 + 1] ^ seg[node * 2 + 2]);
    int O = (seg[node * 2 + 1] | seg[node * 2 + 2]);

    if (hight & 1)
    {
        if (h & 1)  return X;
        else return O;
    }

    else
    {
        if (h & 1)  return O;
        else return X;
    }

    return 1 ;
}

void build(int node , int s , int e ,  int h)
{
    if(s==e)
    {
        seg[node]  = v[s] ;
        hight = h ;
        return ;
    }

    int mid = midpoint(s,e) ;

    build(node * 2 + 1, s, mid, h + 1);
    build(node * 2 + 2, mid + 1, e, h + 1);

    if(s!=e)  seg[node] = opration(node, h) ;
    
}

void update(int node , int s , int e  , int index , int val , int h)
{
    if(s==e)
    {
        seg[node] = val ;
        return ; 
    }

    int mid =  midpoint(s,e) ;

    if (index <= mid)
        update(node * 2 + 1, s, mid, index, val, h + 1);
    
    else
        update(node *2 + 2 , mid + 1, e, index, val, h + 1);

    if(s!=e)  seg[node]  = opration(node,h) ;

}


signed main()
{
    FAST 

    int n , m ;  cin >> n >> m ;  
    // n = 2*n ; 
    n = pow(2, n);
    v.resize(n) ;
    for(int i = 0 ; i < n ; i++)    cin >> v[i] ;
    build(0,0,n-1,1) ;

    while(m--)
    {
        int p , q ;
        cin >> p >> q   ;
        --p ;
        update(0,0,n-1,p,q,1) ;
        cout << seg.front() << nl ;
    }
}

