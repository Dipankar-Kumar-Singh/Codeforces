#include <bits/stdc++.h>
using namespace std;
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

vector<vector<int>> g ;
vector<vector<int>> dp ; // dp[a][b] --> Len of Longest Palandromic Subseq from A <--> B
vector<vector<int>> parent ; 

// par[a][b] --> parent of b IF COMMING FROM A --> 
// PARENT[ SOURCE ] [ NODE ] ---> PREV_VERTEX OF _NODE_ IF COMMING FROM SOURCE . OR ...NEXT VERTEX IN PATH OF _NODE_ IF GOING TOWRODS SOURCE  
// NODE >--[THIS]-------------> SOUCE  --> THIS -->   PAR[ SOUCE ][ NODE ] 
// IN PATH OF A --------X--> B  ==> X is the just previous node IF comming from A 
// parent[a][b] --> X  ||  A --- B simple path ko PARENT GRID ki help sey traveerse kar rahey hai ..
// JUST SIMIALR TO LONGEST COMMON SUBSTRING .. if S[i] == s[j] ==> take help of middle --> if middle a pal , then exteen .. 
// if dp[i +  1][ j -  1] == 1 ==> a palandrome ...  then if s[i] == s[j] ==> dp[i][j] = 1 also a palndrome --> EXTENDED THAT BOUNDRIES 


// PAR MAXTIX is acting like a linear path that is tacable from a--> b or b -->a 


int n ;
string s  ;

void dfs(int node , int par , int source)
{
    // CONSTRUCING PARENT GRID .. 
    parent[source][node] = par ;  
    for(auto child : g[node])
    {
        if(child == par) continue ;
        dfs(child , node , source) ;
    }
}

int rec(int a , int b)
{
    // Max len subsequce in simple path fron a <-----> b
    
    if(dp[a][b] != -1)
        return dp[a][b] ;

    if(a == b) {dp[a][b] = 1 ; return dp[a][b] ;}

    // case for lenght of 2 ...
    if(parent[a][b] == a)
    {
        if(s[a] == s[b]) dp[a][b] = dp[b][a] = 2 ;
        else dp[a][b] = dp[b][a] = 1 ;
        return dp[a][b] ;
    }

    if(s[a] == s[b])
    {
        // rec(l + 1 , r - 1) Analogy in case of Linear vector .. 
        // Taken two end points . now move in middle
        //          A - X -------------------------------- Y - B 
        //              L -------------------------------- R           

        int L = parent[b][a] ; //  parent of A if comming from B ==> X 
        int R = parent[a][b] ; //  Parent of B if comming from A ==> Y
        dp[a][b] = 2 + rec( L , R );
    }

    else 
    {
        int takeA_leaveB = rec(a , parent[a][b]) ;  // rec( a , prev node of B if comming from A )
        int takeB_leaveA = rec(parent[b][a] , b) ;  // rec( next node of A if going TOWORDS B ,  b ) ;
        dp[a][b] = max(takeA_leaveB , takeB_leaveA) ;
    }

    return dp[a][b] ;

}

void solve()
{
    cin >> n ;
    g = vector<vector<int>> ( n + 10 ) ;
    parent = vector<vector<int>>(n + 10, vector<int>(n + 10));
    dp = vector<vector<int>>(n + 10, vector<int>(n + 10, -1));
    cin >> s;

    s = "#"  +  s ; // TO MAKE  ONE BASED INDEXing 

    for(int i =  1 ; i < n ; i++) 
    {
        int x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    for(int source = 1 ; source <= n ; source++)
    {
        dfs(source,source,source) ;
    }

    int maxlen = 0 ;

    for(int a = 1 ; a <= n ; a++)
        for(int b = 1 ; b <= n  ; b++)
            maxlen = max( maxlen , rec(a,b)) ;

    cout << maxlen << nl ;


}

signed main() { FAST TestCases solve(); }