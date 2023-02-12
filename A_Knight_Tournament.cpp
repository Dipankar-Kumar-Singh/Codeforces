#include "bits/stdc++.h"
using namespace std;


// FINAL CLEAN CODE SUBMIT !!

// OLD AC SOL MAI ... N = 4e5 was enough ...
// but because we have called lazy in each and every fun at start
// Limt*4 tak acccess kar raha tha our lazy fun .. thus ... bigger arr ki zarurat pard gai ...


// TO OVER COME THIS PROBLEM --> WE know ... In question kabhi bhi .. Xe5 sey uppar ka leaf node hoga nahi ...
// then jab lazy[2*node] kar rahey ho , then ek check laga saktey hia .... if(2*node >= 4*N(FULL LIMIT)) --> out of limit --> then return ;

/* -------------------------------------------------------------------------- */
/*                       MY MISTAKE EARLIER ::::::::::::                      */
/* -------------------------------------------------------------------------- */

    // mistake -> IN GET / QUERY FUN 

// I was taking the value /// return seg[v] [ query] 
// without first propogation the value to childrent  in recusive call //

// so solveLazy fun should be above [ BEFORE ACCCESING ANY NODE --> FIRST Propogate ]
// and it's good idea to propogate to it's chilren before calling recursive call ..


#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define all(x)  (x).begin() , (x).end()
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 
#define N 300010 

vector < int > t (4*N) ;
vector < int > lazy (4*N) ;

void solveLazy(int n)
{
    if(lazy[n]==0) return ; // NO REMANING UPDATE
    t[n] = lazy[n] ; 
    if(2*n+1 >= 4*N) return ;
    lazy[2*n] = lazy[2*n + 1] = lazy[n] ;
    lazy[n] = 0 ;
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    
    solveLazy(v) ;  /// VVIP LOCATIN 
    if (l > r)  return;

    if (l == tl && tr == r) {
        lazy[v] = new_val ;
        return ;
    }

    int tm = (tl + tr) / 2;
    update(v*2, tl, tm, l, min(r, tm), new_val);
    update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    
}

int get(int v, int tl, int tr, int pos) {
    
    solveLazy(v) ;  // VVVVVVVVVIIIIIIPPPPP LOCATION

    if (tl == tr) {
        return t[v];        
    }

    int tm = (tl + tr) / 2;
    if (pos <= tm)  return get(v*2, tl, tm, pos);
    else  return get(v*2+1, tm+1, tr, pos);
}


void segment_tree_sol()
{
    int n , m ;
    cin >> n >>  m ;
    vector<vector<int>> qr ;
    while (m--)
    {
        int x , y, z ; cin >> x >> y >> z ; 
        qr.push_back({x,y,z}) ;
    }
    reverse(all(qr)) ;
    for(auto &vv:qr)
    {
        int& x = vv[0] , y = vv[1] , z = vv[2] ;
        update(1,1, n, x , z -1 , z) ;
        update(1,1, n,  z + 1,  y , z) ;
    }

    for(int i = 1 ; i <= n; i++)
    {
        cout << get(1, 1, n, i) << ' ' ;
    }
}


signed main()
{
    FAST 
    segment_tree_sol() ;

}
