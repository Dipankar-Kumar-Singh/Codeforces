#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define Google_Output(t,ans) cout << "Case #" << t << ": " << ans << "\n" ;

void solve(int Test)
{
    int ans = 0 ; 

    int n ; cin >> n; 
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;
    sort(all(v)) ;

    reverse(all(v)) ;

    cout << (v[0] + v[1]) << nl ;
    

   
}

signed main(){

    FAST 
    int Total_Test ; cin >> Total_Test ;
    for(int TEST = 1 ; TEST <=  Total_Test ; TEST++)
    {
        solve(TEST) ;
    }
}