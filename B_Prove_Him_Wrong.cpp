#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

int const LIMIT = 1e9 ;
#define ll long long
ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}

void solve()
{
   int n ; cin >> n; 

   vector<int> v(n,1) ;

    for(int i = 1 ; i < n ; i++)
    {
        v[i] = 3*v[i-1] ;
        if(v[i]>LIMIT) 
        {
            cout << "NO\n" ;
            return ;
        }
    }

    cout << "YES\n" ;
    for(auto &x : v) cout << x << " " ;
    cout << nl ;
    

}

signed main()
{   FAST  

    TestCases  
    solve() ;  



}

