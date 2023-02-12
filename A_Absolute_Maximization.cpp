    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    int s = 0 ;
    int a = -1 ;
    for(auto &x : v) cin >> x , s |= x , a &= x;

   
    cout << s - a << nl ;

    
}

signed main() { FAST TestCases solve(); }
