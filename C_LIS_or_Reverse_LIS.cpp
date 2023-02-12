#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n; cin >> n; int ans = 0 ;
    vector<int> v(n) ;  map<int,int> fr ;
    for(auto &x : v) cin >> x , fr[x]++ ;
    int many = 0 , one = 0;
    for (auto [x, f] : fr)  (f == 1 ? one : many)++;
    cout << many + (one+1)/2 << nl ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

