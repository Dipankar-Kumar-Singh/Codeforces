#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int const maxN = 4e4 ;
vector<int> palandrome ;
vector<int> dp(maxN+100) ;

bool isPal(int &n)
{
    auto s  = to_string(n) ;
    auto rs = s ;
    reverse(all(rs)) ;
    return (rs==s) ;
}

void solve()
{
    int n ; cin >> n ;
    cout << dp[n] << nl ;
}

signed main()
{   FAST  

    for(int i = 1 ; i <= maxN ; i++ )
    {
        if(isPal(i)) palandrome.push_back(i) ;   
    }

    dp[0] = 1 ;

    cerr << palandrome.size() << nl ; 

    for(int i = 1 ; i <= maxN ; i++)
    {
        for(auto &x : palandrome)
        {
            if(x>i) break;
            dp[i] += dp[i-x] ;
        }

    }

    // for(int i = 1 ; i <= 12 ; i++) cout << dp[i] << " " ;


    TestCases  
    solve() ;  

}

