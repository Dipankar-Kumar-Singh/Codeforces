#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 




signed main()
{
    vector<int> v  = { 1, 2 , 1 , 9  , 2 , 1 , 2 , 2 , 3 , 9 , 1 } ;

    sort(all(v)) ;
    v.resize(unique(all(v))-v.begin()) ;

    for(auto x : v) cout << x << " " ;
}