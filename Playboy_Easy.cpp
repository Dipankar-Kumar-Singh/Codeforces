#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int const N = 1e5 ;
long long fact[N + 1];


void initfact() {
    // IMPORTANT : NOTE : DO INSITIALIZE ....
    fact[0] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1] * i);
    }
}

void solve()
{
   int n ; cin >> n; 
   cout << fact[n] << nl ;
}

signed main()
{   FAST  
   initfact() ;

    TestCases  
    solve() ;  

}

