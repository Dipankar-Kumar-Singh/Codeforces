#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
   int n;   cin >> n;
   int x = 0 ; cin >> x ;
   vector<int> v(n);  for (auto &x : v) cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(2,0));

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(
            (dp[i - 1][0] + ((v[i - 1] + x) ^ (v[i] + x))),
            (dp[i - 1][1] + ((v[i - 1]) ^ (v[i] + x))));

        dp[i][1] = max(
            (dp[i - 1][0] + ((v[i - 1] + x) ^ (v[i]))),
            (dp[i - 1][1] + ((v[i - 1]) ^ (v[i]))));
    }

    cout << max(dp[n-1][0],dp[n-1][1]) << nl  ;

}
signed main(){   FAST      TestCases      solve() ;  }



