#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}

void solve()
{
   
    string s ; cin >> s ;
    string t ; cin >> t ;

    if (t.find('a') == string::npos )
    {
        int n = s.size() ;
        int ans = power(2,n) ;
        cout << ans << nl ;
    }

    else 
    {
        if(t.size()==1)
        {
            cout << 1 << nl ;
        }

        else 
        {
            cout << -1 << nl ;
        }
    }
    

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

