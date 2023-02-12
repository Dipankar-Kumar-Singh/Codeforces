#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   
    int n ; cin >>  n ;

    vector<int> v(n) ; for(auto &x : v) cin >> x ; 

    int odd{} , even{} ;

    for(auto &x : v)
    {
        ((x&1) ? odd : even)++ ;
    }

    cout << min(n-odd, n-even) << nl ;


}

signed main()
{   FAST  
    solve() ;  
}

