#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

int const INF  = 1e18 ;
int test = 0 ;

void solve()
{

    int n ; cin >> n ;
    vector<int> a(n) ; for(auto &x : a) cin >> x ; 
    vector<int> b(n) ; for(auto &x : b) cin >> x ; 

    int ans = 0 ;

    for(int i = 0 ; i < n; i++)
    {
        int x = a[i] ; ;
        int y = b[i] ;
        int z = a[i] + b[i] - (a[i] * b[i]);

        int toadd = max({x,y,z}) ;
        if(toadd > 0 ) ans += toadd ;
    }

    cout << ans ;
}

signed main(){  FAST      solve() ; }