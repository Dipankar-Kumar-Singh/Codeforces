    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 
int __case__ = 1 ;

vector<string> color ;

int m = 0 ;

int flipRow(int i){
    return !i ;
}

bool dfs(int i , int j )
{
    if (j == m - 1)
        return color[i][j] == 'B';

    if(color[i][j] == 'W') return 0 ;
    color[i][j] = 'W' ;

    if (color[ flipRow(i) ][j] == 'B')
        return dfs( flipRow(i) , j );

    else if (color[i][j + 1] == 'B')
        return dfs(i, j + 1);

    return false ;
}

void solve()
{
    cin >> m ;
    int ans = 0 ;

    color = vector<string>(2) ;
    cin >> color[0] >>  color[1] ;
    auto colorCopy = color ;

    ans |= dfs(0,0) ;       color = colorCopy ;
    ans |= dfs(1,0) ;

    cout << ( ans ? "YES" : "NO") << nl;
}

signed main() { FAST TestCases solve(); }
