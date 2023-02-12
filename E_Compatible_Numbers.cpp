#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int const N = 1<<22 ;
// void fliped(int n) { return (N-1-n) ;}
signed main()
{
    FAST
    int n ; cin >> n ;
    
    vector<int> v(n,-1) ;
    for(auto &x : v) cin >> x ;

    vector<int> dp(N,-1) ;

    for(int i = 0 ;  i < n ; i++)
    {
        dp[v[i]] = v[i] ;
    }

    for(int i = 1; i < N ; i++ )
    {
        for(int j = 0 ; j < 22 ; j++)
        {
            if (i & (1 << j))
            {
                dp[i] = max(dp[i], dp[i - (1 << j)]);
            }
        }
    }

    for(auto &x : v) cout << dp[N-1  - x] << " " ; 
}

