#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;


void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 

    map<int,vector<int>> loc ;
    for(int i = 0 ; i < n ; i++) loc[v[i]].push_back(i) ;

    string s ; cin >> s ; 

    for(auto [val , vec] : loc)
    {
        set<char> ss ;
        for(auto i : vec)
        {
            ss.insert(s[i]) ; 
        }

        if(ss.size()>1)
        {
            cout << "NO" << nl ;
            return ;
        }
    }

    cout << "YES" << nl;
    return ;
    
    

    

    print(ans) ;
}

signed main(){  FAST    TestCases    solve() ; }