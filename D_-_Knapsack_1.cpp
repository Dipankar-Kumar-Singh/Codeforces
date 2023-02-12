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
    int n = 0;
    cin >> n;
    int MAX_CAPACITY = 0;
    cin >> MAX_CAPACITY;

    vector<int> w(n + 1), v(n + 1);

    int inf = 1e9 + 1e2;

    vector<vector<int>> dp(n + 10, vector<int>(MAX_CAPACITY + 10));

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int item = 1; item <= n; item++)
    {
        for (int cap = 1 ; cap <= MAX_CAPACITY; cap++)
        {
            int choiseA = -1;
            int choiseB = -1;

            // take it
            if ((cap - w[item]) >= 0)
                choiseA = dp[item - 1][cap - w[item]] + v[item];
            // new reduced capacity = cap - w[item] ; 

            // not take it
            choiseB = dp[item - 1][cap] + 0;
            // best of two decisions 
            
            dp[item][cap] = max(choiseA, choiseB);
        }
    }

    cout << dp[n][MAX_CAPACITY] << nl ;

}
signed main(){   FAST solve() ;  }



