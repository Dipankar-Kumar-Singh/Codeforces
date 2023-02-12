#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
    int a , b , c , d ;
    cin >> a >> b >> c >> d ;

    int sum = a + b + c + d ;

    if(sum==0)
    {
        cout << 0 << nl ;
    }

    else if(sum<=3)
    {
        cout << 1 << nl ;
    }

    else 
    {
        cout << 2 << nl ;
    }


}
signed main(){   FAST      TestCases      solve() ;  }
