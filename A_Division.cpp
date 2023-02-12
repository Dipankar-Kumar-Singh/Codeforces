#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n ; cin >> n ;
    cout << "Division " ;

    if(n<1400)
        cout << 4 ;
    else if(n>= 1400 and n <1600) cout << 3 ;
    else if(n>= 1600 and n<1900) cout << 2 ;
    else if(n>=1900) cout << 1 ;

    cout << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

