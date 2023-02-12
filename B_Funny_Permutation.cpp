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
    vector<int> v(n) ; 
    iota(all(v),1) ;
    reverse(all(v)) ;

    if(n&1)
    {
        int mid = n/2 ; 
        for(int i = mid , pt = 1 ; i < n;  i++ , pt++)
        {
            v[i] = pt ;
        }
    } 

    if (n!=3 and n!=1)
    {
        for (auto x : v)
            cout << x << " ";
        cout << nl;
    }

    else
        cout << -1 << nl;

}

signed main(){  FAST    TestCases    solve() ; }