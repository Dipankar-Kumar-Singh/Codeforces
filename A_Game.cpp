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
    vector<int> v(n) ;
    for(auto &x : v ) cin >> x ;

    int ans = 0 ;
    int a  = 0 , b = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        if(v[i]==0) {a = i - 1 ; break;}
    }

    for(int i = n -1  ; i >=0  ; i--)
    {
        if(v[i]==0) {b = i + 1 ; break;}
    }

    ans = b - a  ;
    cout << ans << nl ;
    

}

signed main()
{   FAST  

    TestCases  
    solve() ;  



}

