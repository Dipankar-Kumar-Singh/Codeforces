#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int n ;
vector<int> v ;
vector<vector<int>> DP ;

int dp(int l , int r)
{
    if(l==r) return 0 ;
    if(DP[l][r] != -1) return DP[l][r] ;
    return DP[l][r] = v[r] - v[l] + min(dp(l+1,r),dp(l,r-1)) ;
}

void solve()
{
    cin >> n;
    v = vector<int>(n);
    DP = vector<vector<int>>(n+10,vector<int>(n+10,-1)) ;
    for (auto &x : v) cin >> x;
    sort(begin(v), end(v));

    cout << dp(0,n-1) << nl ;

}
signed main(){   FAST    solve() ;  }



