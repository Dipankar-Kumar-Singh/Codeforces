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
    int q ; cin >> q ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 

    vector<int> hightTill(n+1) ;
    partial_sum(all(v),hightTill.begin()+1) ;

    vector<int> maxtill(n+1) ;
    for(int i = 1 ; i <= n ; i++) maxtill[i] = max(maxtill[i-1],v[i-1]) ;

    auto isPossible = [&](int i , int k) -> bool {
        return maxtill[i+1] <= k ;
    };
    
    while(q--)
    {
        int k ; cin >> k ;
        int l = -1 , r = n  ;
        while(r-l>1)
        {
            int mid = midpoint(l,r) ;
            if(isPossible(mid,k)) l = mid ; 
            else r = mid ;
        }

        cout << hightTill[l+1] << " " ;
    }

    cout << nl ;
    
}

signed main(){  FAST    TestCases    solve() ; }