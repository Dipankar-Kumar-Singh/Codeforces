#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
#define ll long long

ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}

void solve()
{

    int n ; cin >> n ;
    int ans = power(2,n)-1 ;
    cout << ans << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  



}

