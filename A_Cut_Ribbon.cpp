#include <bits/stdc++.h>
using namespace std;

int dp[4100][4100] ;
int ans = -1 ;


bool kp(int target , int a , int b ,int c , int p){

    if(dp[p][target] != -1 ){ return dp[p][target] ;}

    if(target<0){return dp[p][target] = false ;}

    if(target == 0) 
    {
        if(target == 0 ) {ans =  max(p,ans) ;}
        return  dp[p][target] = true ;
    }
    
    bool c1 = kp(target-a , a, b, c, p+1) ;
    bool c2 = kp(target-b , a, b, c, p+1) ;
    bool c3 = kp(target-c , a, b, c, p+1) ;

    if(c1 || c2 || c3)
    {
        if(target == 0 )ans =  max(p,ans) ;
        return dp[p][target] = true ;
    }
    else return dp[p][target] = false ;
}


signed main()
{
    memset(dp,-1,sizeof(dp)) ;
    int l , a, b ,c ; 
    cin >> l >> a >> b >> c ;
    kp(l,a,b,c,0) ;
    cout << ans ;
}

