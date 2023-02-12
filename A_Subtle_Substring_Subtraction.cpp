#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    string s ;
    cin >> s ;
    int sum = 0 ;
    for(auto &c : s) 
    {
        sum += (c-'a') + 1 ;
    }

    int n = s.size() ;
    int ans = sum ;

    int lowest =  min((s.front()-'a'+1),(s.back()-'a'+1))  ;
 
    if(n==1)
    {
        cout << "Bob " << ans << nl ;
        return ;
    }

    if(n&1)
    {
        ans -= 2*lowest ;
        cout << "Alice " << ans << nl ;
        return ;
    }

    else 
    {
        cout << "Alice " << ans << nl ;
    }

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

