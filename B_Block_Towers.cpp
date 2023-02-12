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
    int n ; 
    cin >>  n;
    n-- ;

    vector<int> v(n) ;

    int e ; cin >> e ;

    for(int &x : v) cin >> x ;

    sort(all(v)) ;

    for(auto& x : v) 
    {
        if( x < e ) continue; 

        int sum = e + x ;

        int half = sum / 2 ;

        e = half ;
        if((sum&1) == 1) e++ ;
    }


    cout << e << nl ;

    
}

signed main() { FAST TestCases solve(); }
