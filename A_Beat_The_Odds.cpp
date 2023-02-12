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
   int e = 0 , o = 0 ;
   for(auto &x : v)
    {   
        cin >> x ;
        (x&1 ? o : e)++ ;
    }

    cout << min(o,e) << nl ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

