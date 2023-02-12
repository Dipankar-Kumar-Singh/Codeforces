// S E L F   --- S O L V E D 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

vector<int> R , G , B ;

int dp[202][202][202] ;


int rec(int a , int b , int c)
{
    int ans = 0 ;

    if(dp[a][b][c] != -1) return dp[a][b][c] ;

    if (a and b)
        ans = max(ans, (R[a - 1] * G[b - 1]) + rec(a - 1, b - 1, c));

    if (b and c)
        ans = max(ans, (G[b - 1] * B[c - 1]) + rec(a, b - 1, c - 1));

    if (c and a)
        ans = max(ans, (B[c - 1] * R[a - 1]) + rec(a - 1, b, c - 1));

    dp[a][b][c] = ans ;
    return ans ;
}

void solve()
{
    int r , g , b ;
    cin >> r >> g >> b ;

    R = vector<int>(r) ;
    G = vector<int>(g) ;
    B = vector<int>(b) ;

    for (int i = 0; i < 202; i++)
        for (int j = 0; j < 202; j++)
            for (int k = 0; k < 202; k++)
                dp[i][j][k] = -1;

    for(int &item : R) cin >> item ;
    for(int &item : G) cin >> item ;
    for(int &item : B) cin >> item ;

    sort(all(R)) , sort(all(G)) , sort(all(B)) ;
    cout << rec(r, g, b);
}

signed main() { FAST  solve(); }
