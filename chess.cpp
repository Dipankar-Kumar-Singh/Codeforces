#include<bits/stdc++.h>
using namespace std ;

int n , m ;

int  const N = 1e3 ;
int dp[N][N] ;
vector<vector<int>> v ;

int const BLOCKED = -2 ;

int rec(int i , int j )
{
    if(i > n or j > m )
    {
        return 0 ;
    }

    if(i == n or j == m) 
    {
        return 1 ; 
    }

    if(dp[i][j]!=-1) return dp[i][j] ;

    int noofways = 0 ;
    if(v[i+1][j] != BLOCKED) noofways += rec( i + 1 , j ) ;
    if(v[i][j + 1] != BLOCKED) noofways += rec( i , j  + 1) ;

    return dp[i][j] = noofways ;
    
}


int main()
{

}