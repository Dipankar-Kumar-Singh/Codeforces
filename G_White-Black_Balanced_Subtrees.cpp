#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


int ans = 0 ;
void dfs(int n , string &color , vector<vector<int>> &dp, vector<int> g[])
{

    for(auto &child : g[n])
    {
        dfs(child, color, dp, g);

        dp[n][0] += dp[child][0];
        dp[n][1] += dp[child][1];

    }

    if(color[n]=='W') dp[n][1]++ ;
    else dp[n][0]++ ;

    if(dp[n][0]==dp[n][1])
    {
        ans++ ;
    }
}

void solve()
{

    cerr << nl << nl << nl ;

    ans = 0 ;
    int n ; cin >> n ;
    vector<int> g[n+10] ;
    vector<vector<int>> dp(n+11,vector<int>(2,0)) ;

    int root = 1 ;
    for(int i = root + 1 ; i <= n ; i++)
    {
        int par ; cin >> par ;
        g[par].push_back(i) ;
    }

    string color ; color.push_back('W') ;
    for(int i = 0 ; i < n ;i++)
    {
        char c ; cin >> c ;
        color += c ;
    }

    dfs(1,color,dp,g) ;
    cout << ans << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

