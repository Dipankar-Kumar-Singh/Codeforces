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
    int n ; cin >> n ;
    int c ; cin >> c ;
    int cost = 0 ;
    map<int,int> m ;

    for(int i = 0 ; i < n ; i++)
    {
        int x ; cin >> x ;
        m[x]++ ;
    }

    for(auto [x , y] : m)
    {
        cost += (min(y,c)) ;
    }

    cout << cost << nl ;

}

signed main(){  FAST    TestCases    solve() ; }