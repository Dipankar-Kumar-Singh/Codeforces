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

int getdigit(int n)
{
    int count = 0 ;
    while(n)
    {
        count++ ;
        n /= 10 ;
    }
    return count ;
}

void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    
    if(n<10)
    {
        cout << n - 1 << nl ;
    }

    else 
    {
        int d = getdigit(n) ; 
        int x  = 1 ;

        for(int i = 0 ; i < d -1 ; i++) x *= 10 ;

        cout << n - x << " " << nl ;
    }
    
    

    

    // print(ans) ;
}

signed main(){  FAST    TestCases    solve() ; }