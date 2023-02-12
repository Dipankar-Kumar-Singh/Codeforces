#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   int n; 
   cin >> n;
   vector<int> v(n) ;
   for(auto &x : v) cin >> x ;

    map<int,vector<int>> m ;
    for(int i = 0  ; i < n; i++)
    {
        m[v[i]].push_back(i+1) ; 
    }

    vector<int> ans ;

    for(auto &[x,vec] : m)
    {
        if(vec.size()==1)
        {
            cout << -1 << nl ;
            return ;
        }

        reverse(all(vec)) ;

        if(vec.size()&1)
        {
            swap(vec[vec.size()/2] , vec[vec.size()/2+1] ) ;
        }

        for(auto &xx : vec) ans.push_back(xx) ;
    }

    for(auto x : ans) cout << x << " " ;
    cout << nl ;





}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

