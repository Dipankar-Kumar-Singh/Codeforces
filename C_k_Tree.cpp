#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;

int n , k , d ;

int const N = 1e5 ; 
vector<int> dp(N,-1) ;

int ways(int x)
{
    if(x == 0)  return 1 ;
    else if(x == 1 ) return 1 ;
    if(x  < 0 ) return 0 ;
    if(dp[x] != -1) return dp[x] ;

    int w = 0 ; 
    for(int i = 1 ; i <= k ; i++)
    {
        if(x-i >= 0)
           { w += ways(x-i) ;}
    }

    return dp[x] = w ;

}


void dfs(int node , int weight ,int &ans , int found_D)
{
    if(weight > n){ return ; }
    if(weight == n and ( found_D or (node == d)) ) {ans+=weight ; return  ; }
    
    for(int child = 1 ; child <= k ; child++)
    {
        dfs(child , weight += child , ans , (found_D or child == d) ) ;
    }

    return  ;
}

signed main()
{
    FAST 
    cin >> n >> k >> d ;

    // cout << ways(n)  ;

    int a = 0 ; 

    dfs(0,0,a,0)  ;  

    
    cout << a << nl ;
    
}

