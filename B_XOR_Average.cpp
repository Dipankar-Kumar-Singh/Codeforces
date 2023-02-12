#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    int n ; 
    cin >> n;
    
    if(n==1)
    {
        cout << 1 << nl ;
    }

    else if(n==2)
    {
        cout << 1 << " " << 3 << nl ;
    }

    else 
    {
        if(n&1)
        {
            for(int i = 0 ; i < n ; i++ ) cout << 1 << " " ;
            cout << nl  ;
        }

        else
        {
            vector<int> v( n ) ;
            v[ 0 ] = 2 , v[ 1 ] = 8 ;

            for(int i = 2 ; i < n - 2 ; i++)  v[ i ] = 10 ;
            v[n - 1] = 15, v[n - 2] = 15;

            for(auto x : v) cout << x << ' '  ; 
            cout << nl ;
        }
    }
}

signed main() { FAST TestCases solve(); }
