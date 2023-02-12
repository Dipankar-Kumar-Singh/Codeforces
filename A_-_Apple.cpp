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
 
    int x , y , n ; 
    cin >> x >> y >> n ;

    if(3*x <= y)
    {
        cout << n*x << nl ;

    }

    else 
    {
        cout << (n/3)*y + (n%3)*x << nl ;
    }

}

signed main(){  FAST        solve() ; }