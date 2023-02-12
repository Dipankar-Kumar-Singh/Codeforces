#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
    int n ; cin >> n ;  vector<int> v (n) ; 
    for(auto &x : v) {  char c ; cin >> c ;   x = c-'0' ;   }

    int ans = 0 ;

    vector<int> prefix(n+1) ;
    partial_sum(all(v),prefix.begin()+1) ;

    map<int,int> mp ;
    for(int i = 0 ; i < n + 1  ; i++) prefix[i] -= i  , mp[prefix[i]]++ ;

    for (auto &[ _ , y] : mp)
        ans += (y * (y - 1)) / 2;

    cout << ans << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }
