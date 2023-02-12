#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int ans = 0;

map<int,int> m ;
int max_point = 0 ;

const int N = 30000+10 , L = 999;
vector<vector<int>> dp ( N , vector<int> (L)) ;

int dfs(int prev , int cur , int gem , map<int,int> &points){
    
    int l = cur - prev  ;
    int a = l-1 , b = l , c = l+1 ; 

    gem += points[cur]  ;
    ans = max(ans,gem) ;

    if(cur>=max_point) return dp[cur][gem] = gem ;
    if(dp[cur][gem]!=0) return dp[cur][gem];

    int ANS1{0} , ANS2 {0}, ANS3 {0} ;
 
    if( a > 0 )
    { 
        ANS1 = dfs(cur , cur + a , gem , points ) ;
    }   
    ANS2 = dfs( cur , cur + b , gem , points ) ;
    ANS3 = dfs( cur , cur + c , gem , points ) ;

    return dp[cur][gem] = max({ANS1,ANS2,ANS3}) ;

}

signed main()
{
    FAST 
    int n , d ; 
    cin >> n >> d ; 
    int first_point = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        int x ; cin >> x ;
        m[x]++ ;
        max_point = max(max_point,x) ;
    }

    dfs(0,d,0,m) ;

    cout << ans ;
}

